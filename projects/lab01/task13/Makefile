# Makefile for task13
SUBDIRS = awesome-sort test-sort

.PHONY: subdirs $(SUBDIRS)

OUT_DIR := $(CURDIR)/../_build/make-build

subdirs: $(SUBDIRS)
	mkdir -p $(OUT_DIR)
	g++ -o $(OUT_DIR)/test-sort $(OUT_DIR)/test-sort.o $(OUT_DIR)/awesome-sort.a

$(SUBDIRS):
	$(MAKE) -C $@ OUT_DIR=$(OUT_DIR)

test-sort: awesome-sort