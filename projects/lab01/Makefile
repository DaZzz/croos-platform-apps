# Makefile fot qt01
SUBDIRS = task13

.PHONY: subdirs $(SUBDIRS)

subdirs: $(SUBDIRS)
	g++ -o ./_build/awesome-sort _build/awesome-sort.o ./_build/test-sort.a

$(SUBDIRS):
	$(MAKE) -C $@