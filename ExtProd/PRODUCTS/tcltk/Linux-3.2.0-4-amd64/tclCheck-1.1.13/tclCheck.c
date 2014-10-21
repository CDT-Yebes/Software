/*
 *	$Source: /home/nlfm/Working/tclCheck//RCS/tclCheck.c,v $
 *	$Date: 1997/10/29 10:25:50 $
 *	$Revision: 1.1.1.14 $
 *
 *------------------------------------------------------------------------
 *   AUTHOR:  Lindsay Marshall <lindsay.marshall@newcastle.ac.uk>
 *------------------------------------------------------------------------
 *    Copyright 1994-1999 The University of Newcastle upon Tyne (see COPYRIGHT)
 *========================================================================
 *
 */
#ifdef __GNUC__
#ifdef __FreeBSD__
#include <stdlib.h>
#else
#include <malloc.h>
#endif
#else
#include <malloc.h>
#endif
#include <ctype.h>
#include <stdio.h>
#include <string.h>

/*
 *	stack of bracket information
 */
typedef struct Stack_t
{
    char		expecting;
    int			line;
    int			charPos;
    int			doubleQuote;
    struct Stack_t	*next;
} Stack;

Stack *bstack = (Stack *) 0;

void pop() {
    Stack *tmp;

    if ((tmp = bstack) != (Stack *) 0)
    {
	bstack = bstack->next;
	free(tmp);
    }
}

/*
 *	stack of data for generating skeleton printout.
 */
typedef struct ls_t
{
    int		number;
    char	*line;
    char	*nsline;
    struct ls_t	*prev;
} LineStack;

LineStack *lsp = (LineStack *) 0;

void lpop() {
    LineStack *tmp;

    if ((tmp = lsp) != (LineStack *) 0)
    {
	free(lsp->line);
	free(lsp->nsline);
	lsp = lsp->prev;
	free(tmp);
    }
}

int doubleQuote	= 0;		/* true if we are inside double quotes	*/
int lineNo	= 1;	       	/* the current line number		*/
int charNo	= 0;		/* the current character position	*/
int comment	= 0;		/* true if line starts with #		*/
int lstart	= 1;		/* true at start of line		*/

int cMode	= 1;
int eMode	= 0;
int gMode	= 1;
int iMode	= 1;
int jMode	= 0;
int lMode	= 0;
int mMode	= 0;
int qMode	= 0;
int sMode	= 0;
int tMode	= 0;

char sLine[256], nsLine[256];
char *slp	= sLine;
char *nsp	= nsLine;
int sbl		= 0;

int named	= 0;		/* true if file name has been output	*/
char *file	= (char *) 0;	/* cuirrent file			*/

void showFile ()
{
    if (!named && file != (char *) 0)
    {
	printf("File %s:\n", file);
	named = 1;
    }
}

/*
 *	returns opening bracket for closing one.
 */
char opener(char close)
{
    switch (close)
    {
    case '"' : return '"';
    case ')' : return '(';
    case '}' : return '{';
    case ']' : return '[';
    }
    return '@';
}

int isPair(char opn, char cls)
{
    char ch;
    return (ch = opener(cls)) != '@' && ch == opn;
}

char guess_closer(char ch1, char ch2)
{
    if ( ch1 == '}' || ch2 == '}' ) { return '}'; }
    if ( ch1 == ']' || ch2 == ']' ) { return ']'; }
    if ( ch1 == ')' || ch2 == ')' ) { return ')'; }
    return '@';
}

/*
 *	lineMatch compares two skeleton lines to see if they match. That
 *	is they have identical leading space/tab sequences and end with
 *	the matching brackets. Thus :
 *		{
 *		}
 *	are a match. Setting exact to 1 will cause identify cases where l1 is
 *	a matching prefix of l2.
 *
 */
int lineMatch(char *l1, char *l2, int exact)
{
    while (*l1)
    {
	if (*l1 != *l2 && !isPair(*l1, *l2)) { return 0; }
	l1++;
	l2++;
    }
    return (!*l2 || !exact);
}

int closes (char *l1, char *l2)
{
    char *el1 = l1 + (strlen(l1) - 1);

    while (isspace(*l2)) { l2++; }
    return isPair(*el1, *l2);
}

int jCheck()
{
    char *l1, *l2;

    while (lsp != (LineStack *) 0)
    {
	l1 = lsp->nsline + (strlen(lsp->nsline) - 1);
	l2 =  nsLine;
	while (*l2 && l1 >= lsp->nsline)
	{
	    if (!isPair(*l1, *l2)) { return 0; }
	    *l1-- = '\0';
	    l2++;
	}
	if (l1 < lsp->nsline)
	{
	    lpop();
	}
	if (*l2 == '\0') { return 1; }
	strcpy(nsLine, l2);
    }
    return 0;
}

void lCheck()
{
    LineStack *tlp;
    char tline[256];

    if (lsp != (LineStack *) 0)
    {
	if (jMode)
	{ 
	    if (jCheck()) { return; }
	}
	else if (lineMatch(lsp->line, sLine, 1))
	{
	    lpop();
	    return;
	}
	else if (lsp->prev != (LineStack *) 0 &&
		 lineMatch(lsp->prev->line, sLine, 1) &&
		 lineMatch(lsp->prev->line, lsp->line, 0))
	{
	    strcpy(tline, lsp->line);
	    tline[strlen(sLine) - 1] = ' ';
	    if (lineMatch(&tline[strlen(tline) - strlen(sLine)], sLine, 1))
	    {
		lpop();
		lpop();
		return;
	    }
	}
    }
    tlp = (LineStack *) malloc(sizeof(LineStack));
    tlp->number = lineNo;
    tlp->line = strcpy(malloc(strlen(sLine) + 1), sLine);
    tlp->nsline = strcpy(malloc(strlen(nsLine) + 1), nsLine);
    tlp->prev = lsp;
    lsp = tlp;
}

void skeleton(char ch)
{
    if (sMode)
    {
	if (ch == '\n')
	{
	    if (sbl > 0)
	    {
		*slp = '\0';
		*nsp = '\0';
		if (lMode)
		{
		    lCheck();
		}
		else
		{
		    showFile();
		    fprintf(stdout, "%5d : %s\n", lineNo, sLine);
		}
	    }
	    slp = sLine;
	    nsp = nsLine;
	    sbl = 0;
	}
	else if (mMode && slp != sLine && isPair(slp[-1], ch))
	{
	    slp--;
	    nsp--;
	    sbl -= 1;
	}
	else
	{
	    *slp++ = ch;
	    if (!isspace(ch)) {
		sbl += 1;
		*nsp++ = ch;
	    }
	}
    }
}

void stack (char ch)
{
    Stack *tmp = (Stack *) malloc(sizeof(Stack));
    tmp->expecting = ch;
    tmp->line = lineNo;
    tmp->charPos = charNo;
    tmp->doubleQuote = doubleQuote;
    tmp->next = bstack;
    bstack = tmp;
    skeleton(opener(ch));
}

void unstack(char ch)
{
    char lch;
    Stack *tmp;

    skeleton(ch);
    if ((lch = ((bstack == (Stack *) 0) ? ' ' : bstack->expecting)) == ch)
    {
	doubleQuote = bstack->doubleQuote;
	pop();
    }
    else if (lch == ' ')
    {
	showFile();
	printf("Unmatching %c : line %d char %d\n", ch, lineNo, charNo);
    }
    else if (doubleQuote)
    {
	if (ch == '"')
	{ /* closing the string */
	    while (bstack->expecting != '"')
	    {
		if (iMode)
		{
		    showFile();
		    printf("Inside a string: unmatched %c ending line %d char %d\n", 
			   opener(bstack->expecting), lineNo, charNo);
		}
		pop();
	    }
	    doubleQuote = bstack->doubleQuote;
	    pop();
	}
	else if (iMode)
	{
	    showFile();
	    printf("Inside a string: unmatched %c on line %d char %d\n",
		   ch, lineNo, charNo);
	}
    }
    else
    {
	if (gMode)
	{
	    char cch, och; /* the guessed close and opener character */
	    cch = guess_closer(ch, lch);
	    och = opener(cch);
	    while ((bstack != (Stack *) 0) && bstack->expecting != cch)
	    {
		showFile();
		printf("Expecting %c got %c : line %d char %d (balancing %c%c)\n",
		       lch, ch, lineNo, charNo, och, cch);
		pop();
	    }
	    if ( ch == cch )
	    { /* synchronize at this point in the stack */
		pop();
		return;
	    }
	}
	showFile();
	printf("Expecting %c got %c : line %d char %d\n",
	       lch, ch, lineNo, charNo);
    }
}

void doQuote (char prev, char post)
{
    if (doubleQuote)
    {
	if (!comment && !isspace(post) && post != ']' && post != '}' &&
	    post != ')' && post != '\\' && post != ';')
	{
	    printf("Extra characters after string : line %d char %d\n", lineNo, charNo);
	}
	unstack('"');
    }
    else if (tMode || isspace(prev) || prev == '{' || prev == '(' || prev == '[')
    {
	stack('"');
	doubleQuote = 1;
    }
    lstart = 0;
}

void openParen (char prev)
{
    if (bstack != (Stack *) 0 && bstack->expecting != ']' && !comment)
    {
	stack(')');
    }
    lstart = 0;
}

void closeParen (char prev)
{
    if (bstack != (Stack *) 0 && bstack->expecting != ']' && !comment)
    {
	unstack(')');
    }
    lstart = 0;
}

void newline (int quote)
{
    int done = 0;

    skeleton('\n');
    if (!quote && !doubleQuote)
    {
#if 0
	while (bstack != (Stack *) 0 && !done)
	{
	    switch (bstack->expecting)
	    {
	    case ')' :
		showFile();
		printf("Missing ( : line %d\n", bstack->line);
		break;
	    case ']' :
		showFile();
		printf("Missing ] : line %d\n", bstack->line);
		break;
	    default :
		done = 1;
		continue;
	    }
	    pop();
	}
#endif
	comment = 0;
	lstart = 1;
    }
    lineNo += 1;
    charNo = 0;
}

void process(FILE * desc)
{
    int ch, prev, bsp = 0, quote = 0, nch;

    doubleQuote = 0;
    lineNo = 1;
    charNo = 0;
    bstack = (Stack *) 0;
    comment = 0;
    lstart = 1;
    prev = ' ';
    while ((ch = getc(desc)) != EOF)
    {
	charNo += 1;
	if (ch == '\n')
	{
	    if (eMode && bsp)
	    {
		printf("\\ followed by blank space at the end of line %d.\n", lineNo);
	    }
	    newline(quote);
	    bsp = 0;
	}
	else if (!quote)
	{
	    if (ch == '\\') { bsp = 0; lstart = 0; quote = 1 ; continue; }
	    if (ch == ' ' || ch == '\t')
	    {
		if (lstart) { skeleton(ch); }
	    }
	    else
	    {
		bsp = 0;
		switch (ch)
		{
		case '\t':
		case ' ' :
		    break;
		case '"' :
		    nch = getc(desc);
		    ungetc(nch, desc);
		    doQuote(prev, nch);
		    break;
		case '{' :
		    if (!comment || bstack != (Stack *) 0)
		    {
			stack('}');
		    }
		    lstart = 0;
		    break;
		case '[' :
		    if (!comment || bstack != (Stack *) 0)
		    {
			stack(']');
		    }
		    doubleQuote = 0;
		    lstart = 0;
		    break;
		case '}' :
		case ']' :
		    if (!comment || bstack != (Stack *) 0)
		    {
			unstack(ch);
		    }
		    lstart = 0;
		    break;
		case '(' :
		    openParen(prev);
		    break;
		case ')' :
		    closeParen(')');
		    break;
		case '#' :
		    if (lstart && cMode) { comment = 1; }
		default:
	            lstart = 0;
	            break;
		}
	    }
	}
	else if (ch == ' ' || ch == '\t') { bsp = 1;}
	quote = 0;
	prev = ch;
    }
}

void rprint(LineStack *lp)
{
    if (lp != (LineStack *) 0)
    {
	rprint(lp->prev);
	free(lp->prev);
	showFile();
	fprintf(stdout, "%5d : %s\n", lp->number, lp->line);
	free(lp->line);
	free(lp->nsline);
    }
}

void destack () {
    LineStack *tlp;
    while (bstack != (Stack *) 0)
    {
	showFile();
	printf("%c missing, opened on line %d char %d\n", bstack->expecting,
	       bstack->line, bstack->charPos);
	pop();
    }
    if (lMode)
    {
	rprint(lsp);
	lsp = 0;
    }
}

#ifndef __FreeBSD__
#endif

int main(int argc, char **argv)
{
    int flag;
    FILE  *desc;
    extern int optind;

    while ((flag = getopt(argc, argv ,"cegijlmqst")) != -1)
    {
	switch (flag)
	{
	case 'c' : cMode = 0; break;
	case 'e' : eMode = 1; break;
        case 'g' : gMode = 0; break;
        case 'i' : iMode = 0; break;
	case 'q' : qMode = 1; break;
        case 'j' : jMode = 1;
	case 'l' : lMode = 1;
	case 'm' : mMode = 1;
	case 's' : sMode = 1; break;
	case 't' : tMode = 1; break;
	}
    }
    if (argv[optind] == (char *) 0)
    {
	file = (char *) 0;
	process(stdin);
	destack();
    }
    else
    {
	while ((file = argv[optind]) != (char *) 0)
	{
	    named = 0;
	    if (!qMode)
	    {
		showFile();
	    }
	    if ((desc = fopen(argv[optind], "r")) == NULL)
	    {
		showFile();
		printf("Cannot be accessed!!\n");
	    }
	    else
	    {
	        process(desc);
	        destack();
	        fclose(desc);
	    }
	    optind += 1;
	}
    }
    return 0;
}
