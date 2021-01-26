## Process this file with automake to produce Makefile.in

AM_CPPFLAGS = \
	$(WX_CXXFLAGS) \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" $(SNAKE_CFLAGS)

AM_CFLAGS =\
	 -Wall \
	 -g \
	 $(WX_CPPFLAGS)

bin_PROGRAMS = snake

snake_SOURCES = \
	main.cc\
	snake.model.cpp \
	snake.view.cpp

snake_LDFLAGS = 

snake_LDADD = \
	$(SNAKE_LIBS) \
	$(WX_LIBS)

