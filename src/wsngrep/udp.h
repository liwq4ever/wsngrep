// Copyright (c) eBPF for Windows contributors
// SPDX-License-Identifier: MIT
#pragma once

typedef struct udphdr
{
    uint16_t uh_sport;        /* source port */
    uint16_t uh_dport;        /* destination port */
    uint16_t uh_ulen;         /* udp length */
    uint16_t uh_sum;          /* udp checksum */
} UDP_HEADER;