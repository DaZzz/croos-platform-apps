# Makefile fot task13
SUBDIRS = awesome-sort test-sort

.PHONY: subdirs $(SUBDIRS)

subdirs: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@

test-sort: awesome-sort