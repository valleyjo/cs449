#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
 .name = KBUILD_MODNAME,
 .init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
 .exit = cleanup_module,
#endif
 .arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__attribute_used__
__attribute__((section("__versions"))) = {
	{ 0x189b029e, "struct_module" },
	{ 0x1b7d4074, "printk" },
	{ 0xdc52c022, "misc_register" },
	{ 0x2da418b5, "copy_to_user" },
	{ 0x79aa04a2, "get_random_bytes" },
	{ 0x56fc11bf, "misc_deregister" },
};

static const char __module_depends[]
__attribute_used__
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "39509465D2B4399B163E9B6");
