#!/usr/bin/python
#
# A simple USB CDC-ACM "driver" written in python.
#
# Copyright: Christophe Augier <christophe.augier@gmail.com>
#

import usb.core
import usb.util
import usb.control

import array

# Look for a specific device and open it
#
dev = usb.core.find(idVendor=0x0483, idProduct=0x5740) # STM32F4 discovery
if dev is None:
    raise ValueError('Device not found')

# Detach interfaces if Linux already attached a driver on it.
#
for itf_num in [0, 1]:
    itf = usb.util.find_descriptor(dev.get_active_configuration(),
                                   bInterfaceNumber=itf_num)
    if dev.is_kernel_driver_active(itf):
        dev.detach_kernel_driver(itf)
    usb.util.claim_interface(dev, itf)


# set control line state 0x2221
# set line encoding 0x2021 (9600, 8N1)
#
#dev.ctrl_transfer(0x21, 0xAA, 0, 0,
#                  array.array('B', [1, 2, 3, 4, 5]))

#dev.write(0x01, 't', interface = 1)
s = dev.read(0x81, 64, interface = 1)
print s.tostring()
#s = dev.read(0x81, 64, interface = 1)
#print s.tostring()
exit()
while(True):
    
    try:
        s = dev.read(0x01, 64, interface = 1)
        if len(s) > 1:
        	print s.tostring() 
    except IOError, arg:
        print 'read failed', arg
        pass

