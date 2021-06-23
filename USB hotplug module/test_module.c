#include <linux/usb.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/hid.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("MAX");
MODULE_DESCRIPTION("Transend hotplug module");
MODULE_VERSION("0.01");

//a simple module that is loaded when usb flash drive is hotplugged

static int max_usb_probe(struct usb_interface *interface,
		const struct usb_device_id *id)
{
    dev_info(&interface->dev, "Max USB Driver Probed: Vendor ID : 0x%02x,\t"
             "Product ID : 0x%02x\n", id->idVendor, id->idProduct);
    return 0;
}

static void max_usb_disconnect(struct usb_interface *interface)
{
    dev_info(&interface->dev, "Max USB Driver Disconnected\n");
}

static const struct usb_device_id id_table[] = {
	{USB_DEVICE(0x8564, 0x1000)},
	{},
};

MODULE_DEVICE_TABLE(usb, id_table);

static struct usb_driver max_usb_driver = {
	.name = "usb_module",
	.probe = max_usb_probe,
	.disconnect = max_usb_disconnect,
	.id_table = id_table,
};

static int __init max_usb_init(void)
{
	printk(KERN_DEBUG "Hello World! (usb driver)");
	return usb_register(&max_usb_driver);
}

static void __exit max_usb_exit(void)
{
	printk(KERN_DEBUG "Goodbye! (usb driver)"); 
	usb_deregister(&msx_usb_driver);

module_init(max_usb_init);
module_exit(max_usb_exit);
