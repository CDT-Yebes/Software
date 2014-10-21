"""
Read snakefood dependencies and output a visual graph.
"""
# This file is part of the Snakefood open source package.
# See http://furius.ca/snakefood/ for licensing details.

import sys, os
from os.path import *

from snakefood.depends import read_depends, eliminate_redundant_depends



prefix = '''
# This file was generated by sfood-graph.

strict digraph "dependencies" {
    graph [
        rankdir = "LR",
        overlap = "scale",
        size = "8,10",
        ratio = "fill",
        fontsize = "16",
        fontname = "Helvetica",
        clusterrank = "local"
        ]

       node [
           fontsize=7
           shape=ellipse
//           style=filled
//           shape=box
       ];

//     node [
//         fontsize=7
//       style=ellipse
//     ];

'''
postfix = '''

}
'''

def graph(pairs, write):
    "Given (from, to) pairs of (root, fn) files, output a dot graph."
    write(prefix)
    lines = []
    for (froot, f), (troot, t) in pairs:
        if opts.pythonify_filenames:
            f = normpyfn(f)
            t = normpyfn(t)
        if opts.full_pathnames:
            f = join(froot, f)
            if troot:
                t = join(troot, t)
        if troot is None:
            write('"%s"  [style=filled];\n' % f)
        else:
            write('"%s" -> "%s";\n' % (f, t))
    write(postfix)

def normpyfn(fn):
    "Normalize the python filenames for output."
    if fn is None:
        return fn
    if fn.endswith('.py'):
        fn = fn[:-3]
    fn = fn.replace(os.sep, '.')
    return fn

def main():
    import optparse
    parser = optparse.OptionParser(__doc__.strip())

    parser.add_option('-f', '--full-pathnames', '--full', action='store_true',
                      help="Output the full pathnames, not just the relative.")

    parser.add_option('-p', '--pythonify-filenames', '--remove-extensions',
                      action='store_true',
                      help="Remove filename extensions in the graph and "
                      "replace slashes with dots.")

    parser.add_option('-r', '--redundant', action='store_false', default=True,
                      help="Do not eliminate redundant dependencies.")

    global opts
    opts, args = parser.parse_args()

    if not args:
        args = ['-']
    for fn in args:
        if fn == '-':
            f = sys.stdin
        else:
            f = open(fn)
        depends = read_depends(f)
        if opts.redundant:
            depends = eliminate_redundant_depends(depends)
        graph(depends, sys.stdout.write)


