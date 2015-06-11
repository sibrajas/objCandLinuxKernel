//#define MODULE             
//	#define __KERNEL__	 
	
	#include<linux/module.h>  
//	#include <linux/config.h>  
#include<linux/kernel.h>
 	#include<linux/netdevice.h> 
	
	int rtl8139_open (struct net_device *dev)
	{
		printk("rtl8139_open called\n");
		netif_start_queue (dev);
		return 0;
	}

	int rtl8139_release (struct net_device *dev)
	{
		printk ("rtl8139_release called\n");
		netif_stop_queue(dev);
		return 0;
	}

	static int rtl8139_xmit (struct sk_buff *skb, 
					struct net_device *dev)
	{
		printk ("dummy xmit function called....\n");
		dev_kfree_skb(skb);
		return 0;
	}

/*	int rtl8139_init (struct net_device *dev)
	{
//		dev->open = rtl8139_open;
//		dev->stop = rtl8139_release;
//		dev->hard_start_xmit = rtl8139_xmit;
		printk ("8139 device initialized\n");
		return 0;
	}*/
	static const struct net_device_ops rtl8139_ops = {
		.ndo_open = &rtl8139_open,
		.ndo_stop = rtl8139_release,
		.ndo_start_xmit = rtl8139_xmit,
};
	struct net_device* rtl8139;// = {init: rtl8139_init};

static void lp_setup(struct net_device *dev)
{
        dev->mtu                = (16 * 1024) + 20 + 20 + 12;
        dev->hard_header_len    = ETH_HLEN;     /* 14   */
        dev->addr_len           = ETH_ALEN;     /* 6    */
        dev->tx_queue_len       = 0;
//        dev->type               = ARPHRD_LOOPBACK;      /* 0x0001*/
//        dev->flags              = IFF_LOOPBACK;
        dev->priv_flags        &= ~IFF_XMIT_DST_RELEASE;
	
}
	int rtl8139_init_module (void)
	{
		int result;
//		struct net_device *rtl8139;
		rtl8139->netdev_ops = &rtl8139_ops; 
		strcpy (rtl8139->name, "rtl8139");
		rtl8139 = alloc_netdev(0,"neto", lp_setup);
		if ((result = register_netdev (rtl8139))) {
			printk ("rtl8139: Error %d  initializing card rtl8139 card",result);
			return result;
		}
	return 0;
	}
	
 	void rtl8139_cleanup (void)
	{
		printk ("<0> Cleaning Up the Module\n");
		unregister_netdev (rtl8139);
		return;
	}
	
	module_init (rtl8139_init_module);
	module_exit (rtl8139_cleanup);
