# Version 	: 0.0.1
# Date		: 26.01.2012
# Author 	: Cedric.Bilat@he-arc.ch
#
# Contrainte
#
#	Dans les définitions de variables ci-dessous, ne laisser jamais d'espace à la fin!!!
#

##############
#   public   #
##############

#########
# GCC #
#########

#separateur est espace,sans extension .a, sans prefixe lib
EXCLUDE_LIBRARY_FILES:=
ADD_LIBRARY_FILES:=

#Compilation: (minimal vide)
#/DWIN32 : only for compiling cppTest
CXXFLAGS   = 

#Linkage: (minimal vide)
CXXLDFLAGS = 

#" " necessaire!
#flag seront surchargï¿½es par la suite

##############
#   pivate   #
##############

COMPILATEUR:=nvidia
OS:=Linux

#chargement de la makeFile principale
-include dataProject.mk
-include ../PRODUCTION/MANAGER/makefile/private/makeFileCudaLinux.mk
 
##############
#   END      #
##############