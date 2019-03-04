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
 * acl.c
 */

#include <linux/init.h>
#include <linux/fs.h>
#include <linux/slab.h>
#include "squashfs_fs.h"
#include "xattr.h"
#include "acl.h"

struct posix_acl *squashfs_get_acl(struct inode *inode, int type)
{
	int name_index;
	char *name;
	struct posix_acl *acl = NULL;
	char *value = NULL;
	int retval;

	switch (type) {
	case ACL_TYPE_ACCESS:
		name_index = SQUASHFS_XATTR_POSIX_ACL_ACCESS;
		name = XATTR_POSIX_ACL_ACCESS;
		break;
	case ACL_TYPE_DEFAULT:
		name_index = SQUASHFS_XATTR_POSIX_ACL_DEFAULT;
		name = XATTR_POSIX_ACL_DEFAULT;
		break;
	default:
		BUG();
	}

	retval = squashfs_xattr_get(inode, name_index, name, NULL, 0);
	if (retval > 0) {
		value = kmalloc(retval, GFP_KERNEL);
		if (!value)
			return ERR_PTR(-ENOMEM);
		retval = squashfs_xattr_get(inode, name_index, name, value, retval);
	}
	if (retval > 0)
		acl = posix_acl_from_xattr(&init_user_ns, value, retval);
	else if (retval == -ENODATA || retval == -ENOSYS)
		acl = NULL;
	else
		acl = ERR_PTR(retval);

	kfree(value);

	return acl;
}
