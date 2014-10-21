#
#  MICOService  by Sorin.Mustaca@ravantivirus.com
#

# set debug variable to 1 if you want debug
debug = 1
# set release variable to 1 if you want release
# release = 1

!include ..\..\vstudio.win32

all: micoservice 

!ifdef release
CXXFLAGS        = /I.\  /GS /Gm /nologo /DNDEBUG /EHsc /GR /TP /Zi  
LINKFLAGS       =  /subsystem:console /incremental:yes advapi32.lib
!endif

!ifdef debug
CXXFLAGS        = /I.\  /GS /Gm /nologo /D_DEBUG /MD /EHsc /GR /TP /Zi  
LINKFLAGS       =  /debug /subsystem:console /incremental:yes advapi32.lib
!endif

!ifndef VC8
CXXFLAGS		= $(CXXFLAGS) /Ge
!endif

.SUFFIXES: .cpp .obj

.cpp.obj:
	cl.exe /c $(CXXFLAGS) /Yu"include.h" $< /Fo$*.obj


SRCS = include.obj  NTServMsg.res trace.obj util.obj  criticalsection.obj  service_jobs.obj NtService.obj  MyService.obj  NTServApp.obj 

include.obj: include.cpp include.h
	$(CXX)  $(CXXFLAGS) /Ycinclude.h -c include.cpp  

NTServMsg.res: NTServMsg.rc 
	rc /r NTServMsg.rc

NTServMsg.rc: NTServMsg.mc
	mc NTServMsg.mc

micoservice: $(SRCS)
	link.exe $(LINKFLAGS) $(SRCS) /out:micoservice.exe

clean:
	del *.obj *.exe *.pdb *.pch *.ilk *.bin *.log  *.idb *.res ntservmsg.rc ntservmsg.h *.*.log