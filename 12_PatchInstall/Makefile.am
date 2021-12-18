AM_CFLAGS = -Wall -Wextra -DLOCALE_PATH='"$(localedir)"'
bin_PROGRAMS=guess
pkgdata_DATA=ru/LC_MESSAGES/guess.mo
pkgdatadir = $(localedir)/ru/LC_MESSAGES
man1_MANS = guess.1

@DX_RULES@

%.1:	%
	-$(HELP2MAN) --no-info --output=$@ --name='@PACKAGE_NAME@' ./$<

all-local: doxygen-doc

ru/LC_MESSAGES/guess.mo: ru.po
	mkdir -p `dirname $@`
	msgfmt $< -o $@

ru.po:	messages.pot
	msgmerge -U $@ $<

messages.pot:	guess.pot guess.c
	xgettext --keyword=_ --language=C --add-comments --sort-output guess.c -o messages.new.pot
	cp guess.pot messages.pot
	msgmerge -U messages.pot messages.new.pot

gitclean:
	git clean -df
