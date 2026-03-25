# Microsoft Developer Studio Project File - Name="CDDUMP" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=CDDUMP - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "CDDUMP.MAK".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "CDDUMP.MAK" CFG="CDDUMP - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "CDDUMP - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe
# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "."
# PROP BASE Intermediate_Dir "."
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "."
# PROP Intermediate_Dir "."
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /Gz /MD /W3 /GX /Gy /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /FD /Oxs /GF /c
# ADD CPP /nologo /Gz /MD /W3 /GX /Gy /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /FD /Oxs /GF /c
# ADD BASE RSC /l 0x409 /d "NDEBUG" /c 1252
# ADD RSC /l 0x409 /d "NDEBUG" /c 1252
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib /nologo /version:5.2 /debug /machine:I386 /subsystem:console,4.0 /osversion:5.2 /opt:ref,icf /release
# ADD LINK32 kernel32.lib user32.lib /nologo /version:5.2 /debug /machine:I386 /subsystem:console,4.0 /osversion:5.2 /opt:ref,icf /release
# Begin Target

# Name "CDDUMP - Win32 Release"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\cddb.c
# End Source File
# Begin Source File

SOURCE=.\cddump.c
# End Source File
# Begin Source File

SOURCE=.\read.c
# End Source File
# Begin Source File

SOURCE=.\wav.c
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\common.h
# End Source File
# Begin Source File

SOURCE=.\wav.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\cddump.rc
# End Source File
# End Group
# End Target
# End Project
