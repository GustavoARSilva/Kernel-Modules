#include <linux/module.h>
#include <linux/init.h>
#include <linux/usb.h>
#include <linux/hid.h>

static struct usb_device_id my_usb_id_table [] = {
        { USB_INTERFACE_INFO(USB_INTERFACE_CLASS_HID,
                             USB_INTERFACE_SUBCLASS_BOOT,
                             USB_INTERFACE_PROTOCOL_KEYBOARD) },
        {}
};

MODULE_DEVICE_TABLE(usb, my_usb_id_table);

int __init usb_keyboard_1_init(void)
{
        printk(KERN_INFO "Hello my USB driver 1!\n");

        return 0;
}

void __exit usb_keyboard_1_exit(void)
{
        printk(KERN_INFO "Bye bye my USB driver 1!\n");

        return;
}

module_init(usb_keyboard_1_init);
module_exit(usb_keyboard_1_exit);

MODULE_AUTHOR("Gustavo A. R. Silva <garsilva@embeddedor.com>");
MODULE_DESCRIPTION("USB Keyboard 1");
MODULE_LICENSE("GPL");
