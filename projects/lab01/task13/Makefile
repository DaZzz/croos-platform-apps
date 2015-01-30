# Makefile for task13
SUBDIRS = awesome-sort test-sort

.PHONY: subdirs $(SUBDIRS)

OUT_DIR := $(CURDIR)/../_build/make-build

subdirs: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) $(MAKECMDGOALS) -C $@ OUT_DIR=$(OUT_DIR)

test-sort: awesome-sort


.PHONY: clean

clean:
	rm -rf $(OUT_DIR)

.PHONY: dynamic
dynamic: subdirs