/*
 * Squashfs - a compressed read only filesystem for Linux
 *
 * Copyright (c) 2018
 * Phillip Lougher <phillip@squashfs.org.uk>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2,
 * or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * acl.h
 */

#include <linux/fs.h>
#include <linux/posix_acl_xattr.h>

#ifdef CONFIG_SQUASHFS_POSIX_ACL
extern struct posix_acl *squashfs_get_acl(struct inode *inode, int type);
#else
#define squashfs_get_acl	NULL
#endif
