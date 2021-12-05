CFLAGS = -Wall -Wextra

all: guessInt ru/LC_MESSAGES/ru.mo

guessInt: guessInt.c libintl.h
	gcc $(CFLAGS) /opt/local/lib/libintl.dylib $< -o $@

guessInt.pot: guessInt.c
	xgettext --keyword=_ --language=C --add-comments --sort-output $< -o tmp.pot
	msgmerge --update $@ tmp.pot

ru.po: guessInt.pot
	msgmerge --update $@ $<

ru/LC_MESSAGES/ru.mo: ru.po
	mkdir -p ru/LC_MESSAGES
	msgfmt $< -o $@

clean:
	rm -rf guessInt ru/ tmp.pot

gitclean:
	git clean -df
