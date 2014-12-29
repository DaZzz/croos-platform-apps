# Makefile fot qt01
SUBDIRS = task13

.PHONY: subdirs $(SUBDIRS)

subdirs: $(SUBDIRS)
	g++ -o ./_build/test-sort _build/test-sort.o ./_build/awesome-sort.a

$(SUBDIRS):
	$(MAKE) -C $@