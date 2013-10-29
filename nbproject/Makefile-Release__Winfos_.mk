#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Release__Winfos_
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/426300299/PICProgram.o \
	${OBJECTDIR}/_ext/426300299/PICProgramLine.o \
	${OBJECTDIR}/_ext/426300299/serial.o \
	${OBJECTDIR}/HexClass.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/serialtest.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/serialtest.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/serialtest ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/426300299/PICProgram.o: ../SerialTest/PICProgram.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/426300299
	${RM} $@.d
	$(COMPILE.cc) -O2 -DWINDOWS -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/426300299/PICProgram.o ../SerialTest/PICProgram.cpp

${OBJECTDIR}/_ext/426300299/PICProgramLine.o: ../SerialTest/PICProgramLine.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/426300299
	${RM} $@.d
	$(COMPILE.cc) -O2 -DWINDOWS -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/426300299/PICProgramLine.o ../SerialTest/PICProgramLine.cpp

${OBJECTDIR}/_ext/426300299/serial.o: ../SerialTest/serial.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/426300299
	${RM} $@.d
	$(COMPILE.cc) -O2 -DWINDOWS -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/426300299/serial.o ../SerialTest/serial.cpp

${OBJECTDIR}/HexClass.o: HexClass.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -DWINDOWS -MMD -MP -MF $@.d -o ${OBJECTDIR}/HexClass.o HexClass.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -DWINDOWS -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/serialtest.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
