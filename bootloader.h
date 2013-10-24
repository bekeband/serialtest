/* 
 * File:   bootloader.h
 * Author: user
 *
 * Created on 2013. október 21., 13:25
 */

#ifndef BOOTLOADER_H
#define	BOOTLOADER_H

#ifdef	__cplusplus
extern "C" {
#endif

#define COMMAND_NACK     0x00
#define COMMAND_ACK      0x01
#define COMMAND_READ_PM  0x02
#define COMMAND_WRITE_PM 0x03
#define COMMAND_READ_EE  0x04
#define COMMAND_WRITE_EE 0x05
#define COMMAND_READ_CM  0x06
#define COMMAND_WRITE_CM 0x07
#define COMMAND_RESET    0x08
#define COMMAND_READ_ID  0x09


#ifdef	__cplusplus
}
#endif

#endif	/* BOOTLOADER_H */

