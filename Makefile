all: help

print-sql: print-sql.c
	gcc print-sql.c -o print-sql

sql: print-sql
	./print-sql > diogenis.sql

sqlite: print-sql diogenis.txt
	./print-sql | sqlite3 diogenis.db

clean:
	-@rm diogenis.db diogenis.sql print-sql

install:
	./install.sh

help:
	@echo 'make install     ... installs fortunes file'
	@echo 'make sql         ... creates SQL file'
	@echo 'make sqlite      ... creates SQLite3 database file'
