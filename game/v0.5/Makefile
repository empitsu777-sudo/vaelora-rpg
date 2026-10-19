CLANG ?= clang
CFLAGS = -target armv4t-none-eabi -marm -O2 -ffreestanding -fno-builtin -fno-unwind-tables -fno-asynchronous-unwind-tables -Wall -Wextra -Werror
LDFLAGS = -target armv4t-none-eabi -marm -nostdlib -fuse-ld=lld -Wl,-T,linker.ld -Wl,--gc-sections
ROM = build/vaelora_bellhaven_v05.gba
.PHONY: all clean assets test
all: $(ROM)
assets:
	python tools/restore_props.py
	python tools/build_assets.py
	python tools/make_header.py
$(ROM): assets src/main.c src/save.c src/save.h src/crt0.S linker.ld
	mkdir -p build
	$(CLANG) $(CFLAGS) $(LDFLAGS) -o build/vaelora_bellhaven_v05.elf src/crt0.S src/main.c src/save.c src/assets.c
	llvm-objcopy -O binary build/vaelora_bellhaven_v05.elf $@
	python tools/pad_rom.py
test: all
	python -m unittest discover -s tests -v
clean:
	rm -f build/*.gba build/*.elf src/assets.c src/assets.h src/header.bin
