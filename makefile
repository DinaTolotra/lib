log_prefix = [MAKE]
log_cmd = echo -e 

compiler = cc
compiler_flag = -Wextra -Wall -Werror

build_dir = ./build/
source_dir = ./source/
include_dir = ./include/

$(build_dir)libio.a: build $(build_dir)libio.o
	@$(log_cmd) "$(log_prefix) Creating '$@' static library" 
	@ar -rcs $@ $(build_dir)libio.o

$(build_dir)libio.o: build
	@$(log_cmd) "$(log_prefix) Creating '$@' object file" 
	@$(compiler) $(compiler_flag) -I$(include_dir) -o $(build_dir)libio.o -c $(source_dir)libio.c

build:
	@$(log_cmd) "$(log_prefix) Creating '$@' directory"
	@mkdir -p $(build_dir)

clean:
	@$(log_cmd) "$(log_prefix) Cleaning"
	@rm -r $(build_dir)
