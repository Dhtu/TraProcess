cmd_/home/thtu/exp1/TraProcess.ko := ld -r -m elf_x86_64  -z max-page-size=0x200000 -T ./scripts/module-common.lds  --build-id  -o /home/thtu/exp1/TraProcess.ko /home/thtu/exp1/TraProcess.o /home/thtu/exp1/TraProcess.mod.o ;  true
