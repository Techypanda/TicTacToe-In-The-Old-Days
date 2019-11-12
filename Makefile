 ###############################################################################
 #	Author: Jonathan Wright													   #
 #	Date: 13/10/2019 2:36am                                                    #
 #	Conditional Complimation Tags: SECRET=1, DEBUG=1, EDITOR=1	               #
 ###############################################################################

CC = gcc
CFLAGS = -Wall -Werror -pedantic -ansi -std=c89 -c
EXEC = TicTacToe
OBJS = board.o commonlib.o program.o settings.o userInterface.o game.o list.o log.o
BTEST = boardTestHarness
BOBJS = board.o commonlib.o boardTest.o test.o
STEST = settingsTestHarness
LTEST = listTestHarness
LOGTEST = logTestHarness
LOGOBJS = board.o log.o list.o commonlib.o logTest.o
LOBJS = list.o listTest.o
SOBJS = settings.o test.o settingsTest.o commonlib.o board.o

GAMEH = board.h game.h commonlib.h log.h
LISTH = list.h
LOGH = board.h log.h
PROGRAMH = list.h commonlib.h board.h settings.h userInterface.h
UIH = log.h userInterface.h commonlib.h game.h board.h settings.h
SETTINGSH = settings.h board.h commonlib.h
BOARDH = board.h commonlib.h
COMMONLIBH = commonlib.h

ifdef DEBUG
CFLAGS += -D DEBUG -g # -g for valgrind
DEBUG : clean $(EXEC)
endif
ifdef SECRET
CFLAGS += -D SECRET=1
SECRET : $(EXEC)
endif
ifdef EDITOR
CFLAGS += -D EDITOR=1
EDITOR : $(EXEC)
endif

# Normal Make will not make the test harnesses as they are not marked
$(EXEC) : $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)
# Make STEST will make testharness for settingsTestHarness
#STEST : $(SOBJS)
#	$(CC) $(SOBJS) -o $(STEST)
# Make BTEST will make testharness for boardTestHarness
#BTEST : $(BOBJS)
#	$(CC) $(BOBJS) -o $(BTEST)

#LOGTEST : $(LOGOBJS)
#	$(CC) $(LOGOBJS) -o $(LOGTEST)

#LTEST : $(LOBJS)
#	$(CC) $(LOBJS) -o $(LTEST)

game.o : game.c $(GAMEH)
	$(CC) $(CFLAGS) game.c

#logTest.o : logTest.c
#	$(CC) $(CFLAGS) logTest.c

list.o : list.c $(LISTH)
	$(CC) $(CFLAGS) list.c

#listTest.o : listTest.c
#	$(CC) $(CFLAGS) listTest.c

log.o : log.c $(LOGH)
	$(CC) $(CFLAGS) log.c

program.o : program.c $(PROGRAMH)
	$(CC) $(CFLAGS) program.c

userInterface.o : userInterface.c $(UIH)
	$(CC) $(CFLAGS) userInterface.c

settings.o : settings.c $(SETTINGSH)
	$(CC) $(CFLAGS) settings.c

#settingsTest.o : settingsTest.c
#	$(CC) $(CFLAGS) settingsTest.c

board.o : board.c $(BOARDH)
	$(CC) $(CFLAGS) board.c

commonlib.o : commonlib.c $(COMMONLIBH)
	$(CC) $(CFLAGS) commonlib.c

#boardTest.o : boardTest.c
#	$(CC) $(CFLAGS) boardTest.c

#test.o : test.c
#	$(CC) $(CFLAGS) test.c

clean :
	rm -Rf $(EXEC) $(BTEST) $(STEST) $(LTEST) *.o *.log
	#Remove Log files and O files
