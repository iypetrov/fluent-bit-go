/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*  Fluent Bit Go!
 *  ==============
 *  Copyright (C) 2022 The Fluent Bit Go Authors
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#ifndef FLBGO_PLUGIN_H
#define FLBGO_PLUGIN_H

#include <stdlib.h>

/* This structure is used for doubly linked list node.
 * It matches the one in mk_core/mk_list.h in monkey source code.
 */
struct mk_list
{
    struct mk_list *prev, *next;
};

/* Return values */
#define FLB_ERROR   0
#define FLB_OK      1
#define FLB_RETRY   2

/* Proxy definition */
#define FLB_PROXY_INPUT_PLUGIN    1
#define FLB_PROXY_GOLANG          11

/* This structure is used to represents a plugin configuration property's value.
 * It matches the one in include/fluent-bit/flb_config_map.h in fluent-bit source code.
 */
struct flb_config_map_val {
    union {
        int i_num;
        int boolean;
        double d_num;
        size_t s_num;
        char* str;
        struct mk_list *list;
        struct cfl_variant *variant;
    } val;
    char* raw;
    struct mk_list *mult;
    struct mk_list _head;
};

/* This structure is used to defines a plugin configuration property.
 * It matches the one in include/fluent-bit/flb_config_map.h in fluent-bit source code.
 */
struct flb_config_map {
    int type;
    char *name;
    char *def_value;
    int flags;
    int set_property;
    unsigned long offset;
    char * desc;
    struct flb_config_map_val value;
    struct mk_list _head;
};

/* This structure is used for registration.
 * It matches the one in include/fluent-bit/flb_plugin_proxy.h in fluent-bit source code.
 */
struct flb_plugin_proxy_def {
    int type;
    int proxy;
    int flags;
    char *name;
    char *description;
    int event_type;
    struct flb_config_map *config_map;
};

#endif
