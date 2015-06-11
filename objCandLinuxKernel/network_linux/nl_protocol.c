/**********************************************************
* Example for a network-layer protocol
* Compile:
* gcc -I/lib/modules/'uname -r'/build/include -c file.c
**********************************************************/

#ifndef _KERNEL_
#define _KERNEL_
#endif
#ifndef MODULE
#define MODULE
#endif

#include <linux/module.h>
#include <linux/version.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/skbuff.h>
#include <linux/in.h>
#include <linux/netdevice.h>

MODULE_AUTHOR("Test Author (fixme@Linux-netzwerkarchitektur.de)");
MODULE_DESCRIPTION("Module with a layer-3 test protocol");

#define TEST_PROTO_ID 0x1234
int test_pack_rcv(struct sk_buff *skb, struct net_device *dev, struct
  packet_type *pt);

static struct packet_type test_protocol =
{
//       _constant_htons(TEST_PROTO_ID),
       NULL,
       test_pack_rcv,

      (void *) 1,
      NULL
};

int test_pack_rcv(struct sk_buff *skb, struct net_device *dev, struct
  packet_type *pt)
{
       printk(KERN_DEBUG "Test protocol: Packet Received with length: %u\n",
              skb->len);
       return skb->len;
}

int init_module(void)
{
       dev_add_pack(&test_protocol);
       return 0;
}

void cleanup_module(void)
{
       dev_remove_pack(&test_protocol);
}

