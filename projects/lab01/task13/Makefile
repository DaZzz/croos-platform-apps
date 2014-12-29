# Makefile fot task13
SUBDIRS = awesome-sort test-sort

.PHONY: subdirs $(SUBDIRS)

subdirs: $(SUBDIRS)
	g++ -o ../_build/test-sort ../_build/test-sort.o ../_build/awesome-sort.a

$(SUBDIRS):
	$(MAKE) -C $@

test-sort: awesome-sort