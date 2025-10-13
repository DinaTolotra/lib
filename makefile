log_prefix = [MAKE]
log_cmd = echo

compiler = cc
compiler_flag = -Wextra -Wall -Werror

build_dir = ./build/
source_dir = ./source/
include_dir = ./include/

all: build $(build_dir)libio.a $(build_dir)libstr.a $(build_dir)libfs.a
	@$(log_cmd) "$(log_prefix) Creating $@ static(s) library(ies)"

$(build_dir)libio.a: build $(build_dir)libio.o
	@$(log_cmd) "$(log_prefix) Creating '$@' static library"
	@ar -rcs $@ $(build_dir)libio.o

$(build_dir)libio.o: build
	@$(log_cmd) "$(log_prefix) Creating '$@' object file"
	@$(compiler) $(compiler_flag) -I$(include_dir) -o $(build_dir)libio.o -c $(source_dir)libio.c

$(build_dir)libstr.a: build $(build_dir)libstr.o
	@$(log_cmd) "$(log_prefix) Creating '$@' static library"
	@ar -rcs $@ $(build_dir)libstr.o

$(build_dir)libstr.o: build
	@$(log_cmd) "$(log_prefix) Creating '$@' object file"
	@$(compiler) $(compiler_flag) -I$(include_dir) -o $(build_dir)libstr.o -c $(source_dir)libstr.c

$(build_dir)libfs.a: build $(build_dir)libfs.o
	@$(log_cmd) "$(log_prefix) Creating '$@' static library"
	@ar -rcs $@ $(build_dir)libfs.o

$(build_dir)libfs.o: build
	@$(log_cmd) "$(log_prefix) Creating '$@' object file"
	@$(compiler) $(compiler_flag) -I$(include_dir) -o $(build_dir)libfs.o -c $(source_dir)libfs.c

build:
	@$(log_cmd) "$(log_prefix) Creating '$@' directory"
	@mkdir -p $(build_dir)

clean:
	@$(log_cmd) "$(log_prefix) Cleaning"
	@rm -r $(build_dir)
