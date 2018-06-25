                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.6.0 #9615 (MINGW64)
                                      4 ;--------------------------------------------------------
                                      5 	.module debug
                                      6 	.optsdcc -mmcs51 --model-small
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _UIF_BUS_RST
                                     12 	.globl _UIF_DETECT
                                     13 	.globl _UIF_TRANSFER
                                     14 	.globl _UIF_SUSPEND
                                     15 	.globl _UIF_HST_SOF
                                     16 	.globl _UIF_FIFO_OV
                                     17 	.globl _U_SIE_FREE
                                     18 	.globl _U_TOG_OK
                                     19 	.globl _U_IS_NAK
                                     20 	.globl _ADC_CHAN0
                                     21 	.globl _ADC_CHAN1
                                     22 	.globl _CMP_CHAN
                                     23 	.globl _ADC_START
                                     24 	.globl _ADC_IF
                                     25 	.globl _CMP_IF
                                     26 	.globl _CMPO
                                     27 	.globl _U1RI
                                     28 	.globl _U1TI
                                     29 	.globl _U1RB8
                                     30 	.globl _U1TB8
                                     31 	.globl _U1REN
                                     32 	.globl _U1SMOD
                                     33 	.globl _U1SM0
                                     34 	.globl _S0_R_FIFO
                                     35 	.globl _S0_T_FIFO
                                     36 	.globl _S0_FREE
                                     37 	.globl _S0_IF_BYTE
                                     38 	.globl _S0_IF_FIRST
                                     39 	.globl _S0_IF_OV
                                     40 	.globl _S0_FST_ACT
                                     41 	.globl _CP_RL2
                                     42 	.globl _C_T2
                                     43 	.globl _TR2
                                     44 	.globl _EXEN2
                                     45 	.globl _TCLK
                                     46 	.globl _RCLK
                                     47 	.globl _EXF2
                                     48 	.globl _CAP1F
                                     49 	.globl _TF2
                                     50 	.globl _RI
                                     51 	.globl _TI
                                     52 	.globl _RB8
                                     53 	.globl _TB8
                                     54 	.globl _REN
                                     55 	.globl _SM2
                                     56 	.globl _SM1
                                     57 	.globl _SM0
                                     58 	.globl _IT0
                                     59 	.globl _IE0
                                     60 	.globl _IT1
                                     61 	.globl _IE1
                                     62 	.globl _TR0
                                     63 	.globl _TF0
                                     64 	.globl _TR1
                                     65 	.globl _TF1
                                     66 	.globl _RXD
                                     67 	.globl _PWM1_
                                     68 	.globl _TXD
                                     69 	.globl _PWM2_
                                     70 	.globl _AIN3
                                     71 	.globl _VBUS1
                                     72 	.globl _INT0
                                     73 	.globl _TXD1_
                                     74 	.globl _INT1
                                     75 	.globl _T0
                                     76 	.globl _RXD1_
                                     77 	.globl _PWM2
                                     78 	.globl _T1
                                     79 	.globl _UDP
                                     80 	.globl _UDM
                                     81 	.globl _TIN0
                                     82 	.globl _CAP1
                                     83 	.globl _T2
                                     84 	.globl _AIN0
                                     85 	.globl _VBUS2
                                     86 	.globl _TIN1
                                     87 	.globl _CAP2
                                     88 	.globl _T2EX
                                     89 	.globl _RXD_
                                     90 	.globl _TXD_
                                     91 	.globl _AIN1
                                     92 	.globl _UCC1
                                     93 	.globl _TIN2
                                     94 	.globl _SCS
                                     95 	.globl _CAP1_
                                     96 	.globl _T2_
                                     97 	.globl _AIN2
                                     98 	.globl _UCC2
                                     99 	.globl _TIN3
                                    100 	.globl _PWM1
                                    101 	.globl _MOSI
                                    102 	.globl _TIN4
                                    103 	.globl _RXD1
                                    104 	.globl _MISO
                                    105 	.globl _TIN5
                                    106 	.globl _TXD1
                                    107 	.globl _SCK
                                    108 	.globl _IE_SPI0
                                    109 	.globl _IE_TKEY
                                    110 	.globl _IE_USB
                                    111 	.globl _IE_ADC
                                    112 	.globl _IE_UART1
                                    113 	.globl _IE_PWMX
                                    114 	.globl _IE_GPIO
                                    115 	.globl _IE_WDOG
                                    116 	.globl _PX0
                                    117 	.globl _PT0
                                    118 	.globl _PX1
                                    119 	.globl _PT1
                                    120 	.globl _PS
                                    121 	.globl _PT2
                                    122 	.globl _PL_FLAG
                                    123 	.globl _PH_FLAG
                                    124 	.globl _EX0
                                    125 	.globl _ET0
                                    126 	.globl _EX1
                                    127 	.globl _ET1
                                    128 	.globl _ES
                                    129 	.globl _ET2
                                    130 	.globl _E_DIS
                                    131 	.globl _EA
                                    132 	.globl _P
                                    133 	.globl _F1
                                    134 	.globl _OV
                                    135 	.globl _RS0
                                    136 	.globl _RS1
                                    137 	.globl _F0
                                    138 	.globl _AC
                                    139 	.globl _CY
                                    140 	.globl _UEP1_DMA_H
                                    141 	.globl _UEP1_DMA_L
                                    142 	.globl _UEP1_DMA
                                    143 	.globl _UEP0_DMA_H
                                    144 	.globl _UEP0_DMA_L
                                    145 	.globl _UEP0_DMA
                                    146 	.globl _UEP2_3_MOD
                                    147 	.globl _UEP4_1_MOD
                                    148 	.globl _UEP3_DMA_H
                                    149 	.globl _UEP3_DMA_L
                                    150 	.globl _UEP3_DMA
                                    151 	.globl _UEP2_DMA_H
                                    152 	.globl _UEP2_DMA_L
                                    153 	.globl _UEP2_DMA
                                    154 	.globl _USB_DEV_AD
                                    155 	.globl _USB_CTRL
                                    156 	.globl _USB_INT_EN
                                    157 	.globl _UEP4_T_LEN
                                    158 	.globl _UEP4_CTRL
                                    159 	.globl _UEP0_T_LEN
                                    160 	.globl _UEP0_CTRL
                                    161 	.globl _USB_RX_LEN
                                    162 	.globl _USB_MIS_ST
                                    163 	.globl _USB_INT_ST
                                    164 	.globl _USB_INT_FG
                                    165 	.globl _UEP3_T_LEN
                                    166 	.globl _UEP3_CTRL
                                    167 	.globl _UEP2_T_LEN
                                    168 	.globl _UEP2_CTRL
                                    169 	.globl _UEP1_T_LEN
                                    170 	.globl _UEP1_CTRL
                                    171 	.globl _UDEV_CTRL
                                    172 	.globl _USB_C_CTRL
                                    173 	.globl _TKEY_DATH
                                    174 	.globl _TKEY_DATL
                                    175 	.globl _TKEY_DAT
                                    176 	.globl _TKEY_CTRL
                                    177 	.globl _ADC_DATA
                                    178 	.globl _ADC_CFG
                                    179 	.globl _ADC_CTRL
                                    180 	.globl _SBAUD1
                                    181 	.globl _SBUF1
                                    182 	.globl _SCON1
                                    183 	.globl _SPI0_SETUP
                                    184 	.globl _SPI0_CK_SE
                                    185 	.globl _SPI0_CTRL
                                    186 	.globl _SPI0_DATA
                                    187 	.globl _SPI0_STAT
                                    188 	.globl _PWM_CK_SE
                                    189 	.globl _PWM_CTRL
                                    190 	.globl _PWM_DATA1
                                    191 	.globl _PWM_DATA2
                                    192 	.globl _T2CAP1H
                                    193 	.globl _T2CAP1L
                                    194 	.globl _T2CAP1
                                    195 	.globl _TH2
                                    196 	.globl _TL2
                                    197 	.globl _T2COUNT
                                    198 	.globl _RCAP2H
                                    199 	.globl _RCAP2L
                                    200 	.globl _RCAP2
                                    201 	.globl _T2MOD
                                    202 	.globl _T2CON
                                    203 	.globl _SBUF
                                    204 	.globl _SCON
                                    205 	.globl _TH1
                                    206 	.globl _TH0
                                    207 	.globl _TL1
                                    208 	.globl _TL0
                                    209 	.globl _TMOD
                                    210 	.globl _TCON
                                    211 	.globl _XBUS_AUX
                                    212 	.globl _PIN_FUNC
                                    213 	.globl _P3_DIR_PU
                                    214 	.globl _P3_MOD_OC
                                    215 	.globl _P3
                                    216 	.globl _P2
                                    217 	.globl _P1_DIR_PU
                                    218 	.globl _P1_MOD_OC
                                    219 	.globl _P1
                                    220 	.globl _ROM_CTRL
                                    221 	.globl _ROM_DATA_H
                                    222 	.globl _ROM_DATA_L
                                    223 	.globl _ROM_DATA
                                    224 	.globl _ROM_ADDR_H
                                    225 	.globl _ROM_ADDR_L
                                    226 	.globl _ROM_ADDR
                                    227 	.globl _GPIO_IE
                                    228 	.globl _IP_EX
                                    229 	.globl _IE_EX
                                    230 	.globl _IP
                                    231 	.globl _IE
                                    232 	.globl _WDOG_COUNT
                                    233 	.globl _RESET_KEEP
                                    234 	.globl _WAKE_CTRL
                                    235 	.globl _CLOCK_CFG
                                    236 	.globl _PCON
                                    237 	.globl _GLOBAL_CFG
                                    238 	.globl _SAFE_MOD
                                    239 	.globl _DPH
                                    240 	.globl _DPL
                                    241 	.globl _SP
                                    242 	.globl _B
                                    243 	.globl _ACC
                                    244 	.globl _PSW
                                    245 	.globl _CfgFsys
                                    246 	.globl _mDelayuS
                                    247 	.globl _mDelaymS
                                    248 	.globl _CH554UART0Alter
                                    249 	.globl _mInitSTDIO
                                    250 	.globl _CH554UART0RcvByte
                                    251 	.globl _CH554UART0SendByte
                                    252 	.globl _putchar
                                    253 	.globl _getchar
                                    254 	.globl _CH554UART1Alter
                                    255 	.globl _UART1Setup
                                    256 	.globl _CH554UART1RcvByte
                                    257 	.globl _CH554UART1SendByte
                                    258 	.globl _CH554WDTModeSelect
                                    259 	.globl _CH554WDTFeed
                                    260 ;--------------------------------------------------------
                                    261 ; special function registers
                                    262 ;--------------------------------------------------------
                                    263 	.area RSEG    (ABS,DATA)
      000000                        264 	.org 0x0000
                           0000D0   265 _PSW	=	0x00d0
                           0000E0   266 _ACC	=	0x00e0
                           0000F0   267 _B	=	0x00f0
                           000081   268 _SP	=	0x0081
                           000082   269 _DPL	=	0x0082
                           000083   270 _DPH	=	0x0083
                           0000A1   271 _SAFE_MOD	=	0x00a1
                           0000B1   272 _GLOBAL_CFG	=	0x00b1
                           000087   273 _PCON	=	0x0087
                           0000B9   274 _CLOCK_CFG	=	0x00b9
                           0000A9   275 _WAKE_CTRL	=	0x00a9
                           0000FE   276 _RESET_KEEP	=	0x00fe
                           0000FF   277 _WDOG_COUNT	=	0x00ff
                           0000A8   278 _IE	=	0x00a8
                           0000B8   279 _IP	=	0x00b8
                           0000E8   280 _IE_EX	=	0x00e8
                           0000E9   281 _IP_EX	=	0x00e9
                           0000C7   282 _GPIO_IE	=	0x00c7
                           008584   283 _ROM_ADDR	=	0x8584
                           000084   284 _ROM_ADDR_L	=	0x0084
                           000085   285 _ROM_ADDR_H	=	0x0085
                           008F8E   286 _ROM_DATA	=	0x8f8e
                           00008E   287 _ROM_DATA_L	=	0x008e
                           00008F   288 _ROM_DATA_H	=	0x008f
                           000086   289 _ROM_CTRL	=	0x0086
                           000090   290 _P1	=	0x0090
                           000092   291 _P1_MOD_OC	=	0x0092
                           000093   292 _P1_DIR_PU	=	0x0093
                           0000A0   293 _P2	=	0x00a0
                           0000B0   294 _P3	=	0x00b0
                           000096   295 _P3_MOD_OC	=	0x0096
                           000097   296 _P3_DIR_PU	=	0x0097
                           0000C6   297 _PIN_FUNC	=	0x00c6
                           0000A2   298 _XBUS_AUX	=	0x00a2
                           000088   299 _TCON	=	0x0088
                           000089   300 _TMOD	=	0x0089
                           00008A   301 _TL0	=	0x008a
                           00008B   302 _TL1	=	0x008b
                           00008C   303 _TH0	=	0x008c
                           00008D   304 _TH1	=	0x008d
                           000098   305 _SCON	=	0x0098
                           000099   306 _SBUF	=	0x0099
                           0000C8   307 _T2CON	=	0x00c8
                           0000C9   308 _T2MOD	=	0x00c9
                           00CBCA   309 _RCAP2	=	0xcbca
                           0000CA   310 _RCAP2L	=	0x00ca
                           0000CB   311 _RCAP2H	=	0x00cb
                           00CDCC   312 _T2COUNT	=	0xcdcc
                           0000CC   313 _TL2	=	0x00cc
                           0000CD   314 _TH2	=	0x00cd
                           00CFCE   315 _T2CAP1	=	0xcfce
                           0000CE   316 _T2CAP1L	=	0x00ce
                           0000CF   317 _T2CAP1H	=	0x00cf
                           00009B   318 _PWM_DATA2	=	0x009b
                           00009C   319 _PWM_DATA1	=	0x009c
                           00009D   320 _PWM_CTRL	=	0x009d
                           00009E   321 _PWM_CK_SE	=	0x009e
                           0000F8   322 _SPI0_STAT	=	0x00f8
                           0000F9   323 _SPI0_DATA	=	0x00f9
                           0000FA   324 _SPI0_CTRL	=	0x00fa
                           0000FB   325 _SPI0_CK_SE	=	0x00fb
                           0000FC   326 _SPI0_SETUP	=	0x00fc
                           0000C0   327 _SCON1	=	0x00c0
                           0000C1   328 _SBUF1	=	0x00c1
                           0000C2   329 _SBAUD1	=	0x00c2
                           000080   330 _ADC_CTRL	=	0x0080
                           00009A   331 _ADC_CFG	=	0x009a
                           00009F   332 _ADC_DATA	=	0x009f
                           0000C3   333 _TKEY_CTRL	=	0x00c3
                           00C5C4   334 _TKEY_DAT	=	0xc5c4
                           0000C4   335 _TKEY_DATL	=	0x00c4
                           0000C5   336 _TKEY_DATH	=	0x00c5
                           000091   337 _USB_C_CTRL	=	0x0091
                           0000D1   338 _UDEV_CTRL	=	0x00d1
                           0000D2   339 _UEP1_CTRL	=	0x00d2
                           0000D3   340 _UEP1_T_LEN	=	0x00d3
                           0000D4   341 _UEP2_CTRL	=	0x00d4
                           0000D5   342 _UEP2_T_LEN	=	0x00d5
                           0000D6   343 _UEP3_CTRL	=	0x00d6
                           0000D7   344 _UEP3_T_LEN	=	0x00d7
                           0000D8   345 _USB_INT_FG	=	0x00d8
                           0000D9   346 _USB_INT_ST	=	0x00d9
                           0000DA   347 _USB_MIS_ST	=	0x00da
                           0000DB   348 _USB_RX_LEN	=	0x00db
                           0000DC   349 _UEP0_CTRL	=	0x00dc
                           0000DD   350 _UEP0_T_LEN	=	0x00dd
                           0000DE   351 _UEP4_CTRL	=	0x00de
                           0000DF   352 _UEP4_T_LEN	=	0x00df
                           0000E1   353 _USB_INT_EN	=	0x00e1
                           0000E2   354 _USB_CTRL	=	0x00e2
                           0000E3   355 _USB_DEV_AD	=	0x00e3
                           00E5E4   356 _UEP2_DMA	=	0xe5e4
                           0000E4   357 _UEP2_DMA_L	=	0x00e4
                           0000E5   358 _UEP2_DMA_H	=	0x00e5
                           00E7E6   359 _UEP3_DMA	=	0xe7e6
                           0000E6   360 _UEP3_DMA_L	=	0x00e6
                           0000E7   361 _UEP3_DMA_H	=	0x00e7
                           0000EA   362 _UEP4_1_MOD	=	0x00ea
                           0000EB   363 _UEP2_3_MOD	=	0x00eb
                           00EDEC   364 _UEP0_DMA	=	0xedec
                           0000EC   365 _UEP0_DMA_L	=	0x00ec
                           0000ED   366 _UEP0_DMA_H	=	0x00ed
                           00EFEE   367 _UEP1_DMA	=	0xefee
                           0000EE   368 _UEP1_DMA_L	=	0x00ee
                           0000EF   369 _UEP1_DMA_H	=	0x00ef
                                    370 ;--------------------------------------------------------
                                    371 ; special function bits
                                    372 ;--------------------------------------------------------
                                    373 	.area RSEG    (ABS,DATA)
      000000                        374 	.org 0x0000
                           0000D7   375 _CY	=	0x00d7
                           0000D6   376 _AC	=	0x00d6
                           0000D5   377 _F0	=	0x00d5
                           0000D4   378 _RS1	=	0x00d4
                           0000D3   379 _RS0	=	0x00d3
                           0000D2   380 _OV	=	0x00d2
                           0000D1   381 _F1	=	0x00d1
                           0000D0   382 _P	=	0x00d0
                           0000AF   383 _EA	=	0x00af
                           0000AE   384 _E_DIS	=	0x00ae
                           0000AD   385 _ET2	=	0x00ad
                           0000AC   386 _ES	=	0x00ac
                           0000AB   387 _ET1	=	0x00ab
                           0000AA   388 _EX1	=	0x00aa
                           0000A9   389 _ET0	=	0x00a9
                           0000A8   390 _EX0	=	0x00a8
                           0000BF   391 _PH_FLAG	=	0x00bf
                           0000BE   392 _PL_FLAG	=	0x00be
                           0000BD   393 _PT2	=	0x00bd
                           0000BC   394 _PS	=	0x00bc
                           0000BB   395 _PT1	=	0x00bb
                           0000BA   396 _PX1	=	0x00ba
                           0000B9   397 _PT0	=	0x00b9
                           0000B8   398 _PX0	=	0x00b8
                           0000EF   399 _IE_WDOG	=	0x00ef
                           0000EE   400 _IE_GPIO	=	0x00ee
                           0000ED   401 _IE_PWMX	=	0x00ed
                           0000EC   402 _IE_UART1	=	0x00ec
                           0000EB   403 _IE_ADC	=	0x00eb
                           0000EA   404 _IE_USB	=	0x00ea
                           0000E9   405 _IE_TKEY	=	0x00e9
                           0000E8   406 _IE_SPI0	=	0x00e8
                           000097   407 _SCK	=	0x0097
                           000097   408 _TXD1	=	0x0097
                           000097   409 _TIN5	=	0x0097
                           000096   410 _MISO	=	0x0096
                           000096   411 _RXD1	=	0x0096
                           000096   412 _TIN4	=	0x0096
                           000095   413 _MOSI	=	0x0095
                           000095   414 _PWM1	=	0x0095
                           000095   415 _TIN3	=	0x0095
                           000095   416 _UCC2	=	0x0095
                           000095   417 _AIN2	=	0x0095
                           000094   418 _T2_	=	0x0094
                           000094   419 _CAP1_	=	0x0094
                           000094   420 _SCS	=	0x0094
                           000094   421 _TIN2	=	0x0094
                           000094   422 _UCC1	=	0x0094
                           000094   423 _AIN1	=	0x0094
                           000093   424 _TXD_	=	0x0093
                           000092   425 _RXD_	=	0x0092
                           000091   426 _T2EX	=	0x0091
                           000091   427 _CAP2	=	0x0091
                           000091   428 _TIN1	=	0x0091
                           000091   429 _VBUS2	=	0x0091
                           000091   430 _AIN0	=	0x0091
                           000090   431 _T2	=	0x0090
                           000090   432 _CAP1	=	0x0090
                           000090   433 _TIN0	=	0x0090
                           0000B7   434 _UDM	=	0x00b7
                           0000B6   435 _UDP	=	0x00b6
                           0000B5   436 _T1	=	0x00b5
                           0000B4   437 _PWM2	=	0x00b4
                           0000B4   438 _RXD1_	=	0x00b4
                           0000B4   439 _T0	=	0x00b4
                           0000B3   440 _INT1	=	0x00b3
                           0000B2   441 _TXD1_	=	0x00b2
                           0000B2   442 _INT0	=	0x00b2
                           0000B2   443 _VBUS1	=	0x00b2
                           0000B2   444 _AIN3	=	0x00b2
                           0000B1   445 _PWM2_	=	0x00b1
                           0000B1   446 _TXD	=	0x00b1
                           0000B0   447 _PWM1_	=	0x00b0
                           0000B0   448 _RXD	=	0x00b0
                           00008F   449 _TF1	=	0x008f
                           00008E   450 _TR1	=	0x008e
                           00008D   451 _TF0	=	0x008d
                           00008C   452 _TR0	=	0x008c
                           00008B   453 _IE1	=	0x008b
                           00008A   454 _IT1	=	0x008a
                           000089   455 _IE0	=	0x0089
                           000088   456 _IT0	=	0x0088
                           00009F   457 _SM0	=	0x009f
                           00009E   458 _SM1	=	0x009e
                           00009D   459 _SM2	=	0x009d
                           00009C   460 _REN	=	0x009c
                           00009B   461 _TB8	=	0x009b
                           00009A   462 _RB8	=	0x009a
                           000099   463 _TI	=	0x0099
                           000098   464 _RI	=	0x0098
                           0000CF   465 _TF2	=	0x00cf
                           0000CF   466 _CAP1F	=	0x00cf
                           0000CE   467 _EXF2	=	0x00ce
                           0000CD   468 _RCLK	=	0x00cd
                           0000CC   469 _TCLK	=	0x00cc
                           0000CB   470 _EXEN2	=	0x00cb
                           0000CA   471 _TR2	=	0x00ca
                           0000C9   472 _C_T2	=	0x00c9
                           0000C8   473 _CP_RL2	=	0x00c8
                           0000FF   474 _S0_FST_ACT	=	0x00ff
                           0000FE   475 _S0_IF_OV	=	0x00fe
                           0000FD   476 _S0_IF_FIRST	=	0x00fd
                           0000FC   477 _S0_IF_BYTE	=	0x00fc
                           0000FB   478 _S0_FREE	=	0x00fb
                           0000FA   479 _S0_T_FIFO	=	0x00fa
                           0000F8   480 _S0_R_FIFO	=	0x00f8
                           0000C7   481 _U1SM0	=	0x00c7
                           0000C5   482 _U1SMOD	=	0x00c5
                           0000C4   483 _U1REN	=	0x00c4
                           0000C3   484 _U1TB8	=	0x00c3
                           0000C2   485 _U1RB8	=	0x00c2
                           0000C1   486 _U1TI	=	0x00c1
                           0000C0   487 _U1RI	=	0x00c0
                           000087   488 _CMPO	=	0x0087
                           000086   489 _CMP_IF	=	0x0086
                           000085   490 _ADC_IF	=	0x0085
                           000084   491 _ADC_START	=	0x0084
                           000083   492 _CMP_CHAN	=	0x0083
                           000081   493 _ADC_CHAN1	=	0x0081
                           000080   494 _ADC_CHAN0	=	0x0080
                           0000DF   495 _U_IS_NAK	=	0x00df
                           0000DE   496 _U_TOG_OK	=	0x00de
                           0000DD   497 _U_SIE_FREE	=	0x00dd
                           0000DC   498 _UIF_FIFO_OV	=	0x00dc
                           0000DB   499 _UIF_HST_SOF	=	0x00db
                           0000DA   500 _UIF_SUSPEND	=	0x00da
                           0000D9   501 _UIF_TRANSFER	=	0x00d9
                           0000D8   502 _UIF_DETECT	=	0x00d8
                           0000D8   503 _UIF_BUS_RST	=	0x00d8
                                    504 ;--------------------------------------------------------
                                    505 ; overlayable register banks
                                    506 ;--------------------------------------------------------
                                    507 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        508 	.ds 8
                                    509 ;--------------------------------------------------------
                                    510 ; internal ram data
                                    511 ;--------------------------------------------------------
                                    512 	.area DSEG    (DATA)
      000069                        513 _mInitSTDIO_x_1_16:
      000069                        514 	.ds 4
      00006D                        515 _mInitSTDIO_x2_1_16:
      00006D                        516 	.ds 1
                                    517 ;--------------------------------------------------------
                                    518 ; overlayable items in internal ram 
                                    519 ;--------------------------------------------------------
                                    520 	.area	OSEG    (OVR,DATA)
                                    521 	.area	OSEG    (OVR,DATA)
                                    522 	.area	OSEG    (OVR,DATA)
                                    523 	.area	OSEG    (OVR,DATA)
                                    524 	.area	OSEG    (OVR,DATA)
                                    525 	.area	OSEG    (OVR,DATA)
                                    526 ;--------------------------------------------------------
                                    527 ; indirectly addressable internal ram data
                                    528 ;--------------------------------------------------------
                                    529 	.area ISEG    (DATA)
                                    530 ;--------------------------------------------------------
                                    531 ; absolute internal ram data
                                    532 ;--------------------------------------------------------
                                    533 	.area IABS    (ABS,DATA)
                                    534 	.area IABS    (ABS,DATA)
                                    535 ;--------------------------------------------------------
                                    536 ; bit data
                                    537 ;--------------------------------------------------------
                                    538 	.area BSEG    (BIT)
                                    539 ;--------------------------------------------------------
                                    540 ; paged external ram data
                                    541 ;--------------------------------------------------------
                                    542 	.area PSEG    (PAG,XDATA)
                                    543 ;--------------------------------------------------------
                                    544 ; external ram data
                                    545 ;--------------------------------------------------------
                                    546 	.area XSEG    (XDATA)
                                    547 ;--------------------------------------------------------
                                    548 ; absolute external ram data
                                    549 ;--------------------------------------------------------
                                    550 	.area XABS    (ABS,XDATA)
                                    551 ;--------------------------------------------------------
                                    552 ; external initialized ram data
                                    553 ;--------------------------------------------------------
                                    554 	.area XISEG   (XDATA)
                                    555 	.area HOME    (CODE)
                                    556 	.area GSINIT0 (CODE)
                                    557 	.area GSINIT1 (CODE)
                                    558 	.area GSINIT2 (CODE)
                                    559 	.area GSINIT3 (CODE)
                                    560 	.area GSINIT4 (CODE)
                                    561 	.area GSINIT5 (CODE)
                                    562 	.area GSINIT  (CODE)
                                    563 	.area GSFINAL (CODE)
                                    564 	.area CSEG    (CODE)
                                    565 ;--------------------------------------------------------
                                    566 ; global & static initialisations
                                    567 ;--------------------------------------------------------
                                    568 	.area HOME    (CODE)
                                    569 	.area GSINIT  (CODE)
                                    570 	.area GSFINAL (CODE)
                                    571 	.area GSINIT  (CODE)
                                    572 ;--------------------------------------------------------
                                    573 ; Home
                                    574 ;--------------------------------------------------------
                                    575 	.area HOME    (CODE)
                                    576 	.area HOME    (CODE)
                                    577 ;--------------------------------------------------------
                                    578 ; code
                                    579 ;--------------------------------------------------------
                                    580 	.area CSEG    (CODE)
                                    581 ;------------------------------------------------------------
                                    582 ;Allocation info for local variables in function 'CfgFsys'
                                    583 ;------------------------------------------------------------
                                    584 ;	../../include/debug.c:27: void	CfgFsys( )  
                                    585 ;	-----------------------------------------
                                    586 ;	 function CfgFsys
                                    587 ;	-----------------------------------------
      00098C                        588 _CfgFsys:
                           000007   589 	ar7 = 0x07
                           000006   590 	ar6 = 0x06
                           000005   591 	ar5 = 0x05
                           000004   592 	ar4 = 0x04
                           000003   593 	ar3 = 0x03
                           000002   594 	ar2 = 0x02
                           000001   595 	ar1 = 0x01
                           000000   596 	ar0 = 0x00
                                    597 ;	../../include/debug.c:34: SAFE_MOD = 0x55;
      00098C 75 A1 55         [24]  598 	mov	_SAFE_MOD,#0x55
                                    599 ;	../../include/debug.c:35: SAFE_MOD = 0xAA;
      00098F 75 A1 AA         [24]  600 	mov	_SAFE_MOD,#0xaa
                                    601 ;	../../include/debug.c:42: CLOCK_CFG = CLOCK_CFG & ~ MASK_SYS_CK_SEL | 0x05;  // 16MHz	
      000992 74 F8            [12]  602 	mov	a,#0xf8
      000994 55 B9            [12]  603 	anl	a,_CLOCK_CFG
      000996 44 05            [12]  604 	orl	a,#0x05
      000998 F5 B9            [12]  605 	mov	_CLOCK_CFG,a
                                    606 ;	../../include/debug.c:57: SAFE_MOD = 0x00;
      00099A 75 A1 00         [24]  607 	mov	_SAFE_MOD,#0x00
      00099D 22               [24]  608 	ret
                                    609 ;------------------------------------------------------------
                                    610 ;Allocation info for local variables in function 'mDelayuS'
                                    611 ;------------------------------------------------------------
                                    612 ;n                         Allocated to registers 
                                    613 ;------------------------------------------------------------
                                    614 ;	../../include/debug.c:69: void	mDelayuS( uint16_t n )  // 以uS为单位延时
                                    615 ;	-----------------------------------------
                                    616 ;	 function mDelayuS
                                    617 ;	-----------------------------------------
      00099E                        618 _mDelayuS:
      00099E AE 82            [24]  619 	mov	r6,dpl
      0009A0 AF 83            [24]  620 	mov	r7,dph
                                    621 ;	../../include/debug.c:82: while ( n ) {  // total = 12~13 Fsys cycles, 1uS @Fsys=12MHz
      0009A2                        622 00101$:
      0009A2 EE               [12]  623 	mov	a,r6
      0009A3 4F               [12]  624 	orl	a,r7
      0009A4 60 0D            [24]  625 	jz	00104$
                                    626 ;	../../include/debug.c:83: ++ SAFE_MOD;  // 2 Fsys cycles, for higher Fsys, add operation here
      0009A6 05 A1            [12]  627 	inc	_SAFE_MOD
                                    628 ;	../../include/debug.c:86: ++ SAFE_MOD;
      0009A8 05 A1            [12]  629 	inc	_SAFE_MOD
                                    630 ;	../../include/debug.c:89: ++ SAFE_MOD;
      0009AA 05 A1            [12]  631 	inc	_SAFE_MOD
                                    632 ;	../../include/debug.c:116: -- n;
      0009AC 1E               [12]  633 	dec	r6
      0009AD BE FF 01         [24]  634 	cjne	r6,#0xff,00114$
      0009B0 1F               [12]  635 	dec	r7
      0009B1                        636 00114$:
      0009B1 80 EF            [24]  637 	sjmp	00101$
      0009B3                        638 00104$:
      0009B3 22               [24]  639 	ret
                                    640 ;------------------------------------------------------------
                                    641 ;Allocation info for local variables in function 'mDelaymS'
                                    642 ;------------------------------------------------------------
                                    643 ;n                         Allocated to registers 
                                    644 ;------------------------------------------------------------
                                    645 ;	../../include/debug.c:127: void	mDelaymS( uint16_t n )                                                  // 以mS为单位延时
                                    646 ;	-----------------------------------------
                                    647 ;	 function mDelaymS
                                    648 ;	-----------------------------------------
      0009B4                        649 _mDelaymS:
      0009B4 AE 82            [24]  650 	mov	r6,dpl
      0009B6 AF 83            [24]  651 	mov	r7,dph
                                    652 ;	../../include/debug.c:129: while ( n ) {
      0009B8                        653 00101$:
      0009B8 EE               [12]  654 	mov	a,r6
      0009B9 4F               [12]  655 	orl	a,r7
      0009BA 60 15            [24]  656 	jz	00104$
                                    657 ;	../../include/debug.c:134: mDelayuS( 1000 );
      0009BC 90 03 E8         [24]  658 	mov	dptr,#0x03e8
      0009BF C0 07            [24]  659 	push	ar7
      0009C1 C0 06            [24]  660 	push	ar6
      0009C3 12 09 9E         [24]  661 	lcall	_mDelayuS
      0009C6 D0 06            [24]  662 	pop	ar6
      0009C8 D0 07            [24]  663 	pop	ar7
                                    664 ;	../../include/debug.c:136: -- n;
      0009CA 1E               [12]  665 	dec	r6
      0009CB BE FF 01         [24]  666 	cjne	r6,#0xff,00114$
      0009CE 1F               [12]  667 	dec	r7
      0009CF                        668 00114$:
      0009CF 80 E7            [24]  669 	sjmp	00101$
      0009D1                        670 00104$:
      0009D1 22               [24]  671 	ret
                                    672 ;------------------------------------------------------------
                                    673 ;Allocation info for local variables in function 'CH554UART0Alter'
                                    674 ;------------------------------------------------------------
                                    675 ;	../../include/debug.c:147: void CH554UART0Alter()
                                    676 ;	-----------------------------------------
                                    677 ;	 function CH554UART0Alter
                                    678 ;	-----------------------------------------
      0009D2                        679 _CH554UART0Alter:
                                    680 ;	../../include/debug.c:149: PIN_FUNC |= bUART0_PIN_X;                                                  //串口映射到P1.2和P1.3
      0009D2 43 C6 10         [24]  681 	orl	_PIN_FUNC,#0x10
      0009D5 22               [24]  682 	ret
                                    683 ;------------------------------------------------------------
                                    684 ;Allocation info for local variables in function 'mInitSTDIO'
                                    685 ;------------------------------------------------------------
                                    686 ;x                         Allocated with name '_mInitSTDIO_x_1_16'
                                    687 ;x2                        Allocated with name '_mInitSTDIO_x2_1_16'
                                    688 ;------------------------------------------------------------
                                    689 ;	../../include/debug.c:161: void	mInitSTDIO( )
                                    690 ;	-----------------------------------------
                                    691 ;	 function mInitSTDIO
                                    692 ;	-----------------------------------------
      0009D6                        693 _mInitSTDIO:
                                    694 ;	../../include/debug.c:166: SM0 = 0;
      0009D6 C2 9F            [12]  695 	clr	_SM0
                                    696 ;	../../include/debug.c:167: SM1 = 1;
      0009D8 D2 9E            [12]  697 	setb	_SM1
                                    698 ;	../../include/debug.c:168: SM2 = 0;                                                                   //串口0使用模式1
      0009DA C2 9D            [12]  699 	clr	_SM2
                                    700 ;	../../include/debug.c:170: RCLK = 0;                                                                  //UART0接收时钟
      0009DC C2 CD            [12]  701 	clr	_RCLK
                                    702 ;	../../include/debug.c:171: TCLK = 0;                                                                  //UART0发送时钟
      0009DE C2 CC            [12]  703 	clr	_TCLK
                                    704 ;	../../include/debug.c:172: PCON |= SMOD;
      0009E0 43 87 80         [24]  705 	orl	_PCON,#0x80
                                    706 ;	../../include/debug.c:173: x = 10 * FREQ_SYS / UART0_BUAD / 16;                                       //如果更改主频，注意x的值不要溢出
      0009E3 75 69 11         [24]  707 	mov	_mInitSTDIO_x_1_16,#0x11
      0009E6 75 6A 04         [24]  708 	mov	(_mInitSTDIO_x_1_16 + 1),#0x04
      0009E9 E4               [12]  709 	clr	a
      0009EA F5 6B            [12]  710 	mov	(_mInitSTDIO_x_1_16 + 2),a
      0009EC F5 6C            [12]  711 	mov	(_mInitSTDIO_x_1_16 + 3),a
                                    712 ;	../../include/debug.c:174: x2 = x % 10;
      0009EE 75 7B 0A         [24]  713 	mov	__modulong_PARM_2,#0x0a
      0009F1 F5 7C            [12]  714 	mov	(__modulong_PARM_2 + 1),a
      0009F3 F5 7D            [12]  715 	mov	(__modulong_PARM_2 + 2),a
      0009F5 F5 7E            [12]  716 	mov	(__modulong_PARM_2 + 3),a
      0009F7 85 69 82         [24]  717 	mov	dpl,_mInitSTDIO_x_1_16
      0009FA 85 6A 83         [24]  718 	mov	dph,(_mInitSTDIO_x_1_16 + 1)
      0009FD 85 6B F0         [24]  719 	mov	b,(_mInitSTDIO_x_1_16 + 2)
      000A00 E5 6C            [12]  720 	mov	a,(_mInitSTDIO_x_1_16 + 3)
      000A02 12 0A C3         [24]  721 	lcall	__modulong
      000A05 AC 82            [24]  722 	mov	r4,dpl
      000A07 8C 6D            [24]  723 	mov	_mInitSTDIO_x2_1_16,r4
                                    724 ;	../../include/debug.c:175: x /= 10;
      000A09 75 7B 0A         [24]  725 	mov	__divulong_PARM_2,#0x0a
      000A0C E4               [12]  726 	clr	a
      000A0D F5 7C            [12]  727 	mov	(__divulong_PARM_2 + 1),a
      000A0F F5 7D            [12]  728 	mov	(__divulong_PARM_2 + 2),a
      000A11 F5 7E            [12]  729 	mov	(__divulong_PARM_2 + 3),a
      000A13 85 69 82         [24]  730 	mov	dpl,_mInitSTDIO_x_1_16
      000A16 85 6A 83         [24]  731 	mov	dph,(_mInitSTDIO_x_1_16 + 1)
      000A19 85 6B F0         [24]  732 	mov	b,(_mInitSTDIO_x_1_16 + 2)
      000A1C E5 6C            [12]  733 	mov	a,(_mInitSTDIO_x_1_16 + 3)
      000A1E 12 0C 17         [24]  734 	lcall	__divulong
      000A21 85 82 69         [24]  735 	mov	_mInitSTDIO_x_1_16,dpl
      000A24 85 83 6A         [24]  736 	mov	(_mInitSTDIO_x_1_16 + 1),dph
      000A27 85 F0 6B         [24]  737 	mov	(_mInitSTDIO_x_1_16 + 2),b
      000A2A F5 6C            [12]  738 	mov	(_mInitSTDIO_x_1_16 + 3),a
                                    739 ;	../../include/debug.c:176: if ( x2 >= 5 ) x ++;                                                       //四舍五入
      000A2C 74 FB            [12]  740 	mov	a,#0x100 - 0x05
      000A2E 25 6D            [12]  741 	add	a,_mInitSTDIO_x2_1_16
      000A30 50 15            [24]  742 	jnc	00102$
      000A32 74 01            [12]  743 	mov	a,#0x01
      000A34 25 69            [12]  744 	add	a,_mInitSTDIO_x_1_16
      000A36 F5 69            [12]  745 	mov	_mInitSTDIO_x_1_16,a
      000A38 E4               [12]  746 	clr	a
      000A39 35 6A            [12]  747 	addc	a,(_mInitSTDIO_x_1_16 + 1)
      000A3B F5 6A            [12]  748 	mov	(_mInitSTDIO_x_1_16 + 1),a
      000A3D E4               [12]  749 	clr	a
      000A3E 35 6B            [12]  750 	addc	a,(_mInitSTDIO_x_1_16 + 2)
      000A40 F5 6B            [12]  751 	mov	(_mInitSTDIO_x_1_16 + 2),a
      000A42 E4               [12]  752 	clr	a
      000A43 35 6C            [12]  753 	addc	a,(_mInitSTDIO_x_1_16 + 3)
      000A45 F5 6C            [12]  754 	mov	(_mInitSTDIO_x_1_16 + 3),a
      000A47                        755 00102$:
                                    756 ;	../../include/debug.c:178: TMOD = TMOD & ~ bT1_GATE & ~ bT1_CT & ~ MASK_T1_MOD | bT1_M1;              //0X20，Timer1作为8位自动重载定时器
      000A47 74 0F            [12]  757 	mov	a,#0x0f
      000A49 55 89            [12]  758 	anl	a,_TMOD
      000A4B 44 20            [12]  759 	orl	a,#0x20
      000A4D F5 89            [12]  760 	mov	_TMOD,a
                                    761 ;	../../include/debug.c:179: T2MOD = T2MOD | bTMR_CLK | bT1_CLK;                                        //Timer1时钟选择
      000A4F 43 C9 A0         [24]  762 	orl	_T2MOD,#0xa0
                                    763 ;	../../include/debug.c:180: TH1 = 0-x;                                                                 //12MHz晶振,buad/12为实际需设置波特率
      000A52 AF 69            [24]  764 	mov	r7,_mInitSTDIO_x_1_16
      000A54 C3               [12]  765 	clr	c
      000A55 E4               [12]  766 	clr	a
      000A56 9F               [12]  767 	subb	a,r7
      000A57 F5 8D            [12]  768 	mov	_TH1,a
                                    769 ;	../../include/debug.c:181: TR1 = 1;                                                                   //启动定时器1
      000A59 D2 8E            [12]  770 	setb	_TR1
                                    771 ;	../../include/debug.c:182: TI = 1;
      000A5B D2 99            [12]  772 	setb	_TI
                                    773 ;	../../include/debug.c:183: REN = 1;                                                                   //串口0接收使能
      000A5D D2 9C            [12]  774 	setb	_REN
      000A5F 22               [24]  775 	ret
                                    776 ;------------------------------------------------------------
                                    777 ;Allocation info for local variables in function 'CH554UART0RcvByte'
                                    778 ;------------------------------------------------------------
                                    779 ;	../../include/debug.c:193: uint8_t  CH554UART0RcvByte( )
                                    780 ;	-----------------------------------------
                                    781 ;	 function CH554UART0RcvByte
                                    782 ;	-----------------------------------------
      000A60                        783 _CH554UART0RcvByte:
                                    784 ;	../../include/debug.c:195: while(RI == 0);                                                            //查询接收，中断方式可不用
      000A60                        785 00101$:
                                    786 ;	../../include/debug.c:196: RI = 0;
      000A60 10 98 02         [24]  787 	jbc	_RI,00112$
      000A63 80 FB            [24]  788 	sjmp	00101$
      000A65                        789 00112$:
                                    790 ;	../../include/debug.c:197: return SBUF;
      000A65 85 99 82         [24]  791 	mov	dpl,_SBUF
      000A68 22               [24]  792 	ret
                                    793 ;------------------------------------------------------------
                                    794 ;Allocation info for local variables in function 'CH554UART0SendByte'
                                    795 ;------------------------------------------------------------
                                    796 ;SendDat                   Allocated to registers 
                                    797 ;------------------------------------------------------------
                                    798 ;	../../include/debug.c:207: void CH554UART0SendByte(uint8_t SendDat)
                                    799 ;	-----------------------------------------
                                    800 ;	 function CH554UART0SendByte
                                    801 ;	-----------------------------------------
      000A69                        802 _CH554UART0SendByte:
      000A69 85 82 99         [24]  803 	mov	_SBUF,dpl
                                    804 ;	../../include/debug.c:210: while(TI ==0);
      000A6C                        805 00101$:
                                    806 ;	../../include/debug.c:211: TI = 0;
      000A6C 10 99 02         [24]  807 	jbc	_TI,00112$
      000A6F 80 FB            [24]  808 	sjmp	00101$
      000A71                        809 00112$:
      000A71 22               [24]  810 	ret
                                    811 ;------------------------------------------------------------
                                    812 ;Allocation info for local variables in function 'putchar'
                                    813 ;------------------------------------------------------------
                                    814 ;c                         Allocated to registers r7 
                                    815 ;------------------------------------------------------------
                                    816 ;	../../include/debug.c:215: void putchar(char c)
                                    817 ;	-----------------------------------------
                                    818 ;	 function putchar
                                    819 ;	-----------------------------------------
      000A72                        820 _putchar:
      000A72 AF 82            [24]  821 	mov	r7,dpl
                                    822 ;	../../include/debug.c:217: while (!TI) /* assumes UART is initialized */
      000A74                        823 00101$:
                                    824 ;	../../include/debug.c:219: TI = 0;
      000A74 10 99 02         [24]  825 	jbc	_TI,00112$
      000A77 80 FB            [24]  826 	sjmp	00101$
      000A79                        827 00112$:
                                    828 ;	../../include/debug.c:220: SBUF = c;
      000A79 8F 99            [24]  829 	mov	_SBUF,r7
      000A7B 22               [24]  830 	ret
                                    831 ;------------------------------------------------------------
                                    832 ;Allocation info for local variables in function 'getchar'
                                    833 ;------------------------------------------------------------
                                    834 ;	../../include/debug.c:223: char getchar() {
                                    835 ;	-----------------------------------------
                                    836 ;	 function getchar
                                    837 ;	-----------------------------------------
      000A7C                        838 _getchar:
                                    839 ;	../../include/debug.c:224: while(!RI); /* assumes UART is initialized */
      000A7C                        840 00101$:
                                    841 ;	../../include/debug.c:225: RI = 0;
      000A7C 10 98 02         [24]  842 	jbc	_RI,00112$
      000A7F 80 FB            [24]  843 	sjmp	00101$
      000A81                        844 00112$:
                                    845 ;	../../include/debug.c:226: return SBUF;
      000A81 85 99 82         [24]  846 	mov	dpl,_SBUF
      000A84 22               [24]  847 	ret
                                    848 ;------------------------------------------------------------
                                    849 ;Allocation info for local variables in function 'CH554UART1Alter'
                                    850 ;------------------------------------------------------------
                                    851 ;	../../include/debug.c:253: void CH554UART1Alter()
                                    852 ;	-----------------------------------------
                                    853 ;	 function CH554UART1Alter
                                    854 ;	-----------------------------------------
      000A85                        855 _CH554UART1Alter:
                                    856 ;	../../include/debug.c:255: PIN_FUNC |= bUART1_PIN_X;
      000A85 43 C6 20         [24]  857 	orl	_PIN_FUNC,#0x20
      000A88 22               [24]  858 	ret
                                    859 ;------------------------------------------------------------
                                    860 ;Allocation info for local variables in function 'UART1Setup'
                                    861 ;------------------------------------------------------------
                                    862 ;	../../include/debug.c:265: void	UART1Setup( )
                                    863 ;	-----------------------------------------
                                    864 ;	 function UART1Setup
                                    865 ;	-----------------------------------------
      000A89                        866 _UART1Setup:
                                    867 ;	../../include/debug.c:267: U1SM0 = 0;                                                                   //UART1选择8位数据位
      000A89 C2 C7            [12]  868 	clr	_U1SM0
                                    869 ;	../../include/debug.c:268: U1SMOD = 1;                                                                  //快速模式
      000A8B D2 C5            [12]  870 	setb	_U1SMOD
                                    871 ;	../../include/debug.c:269: U1REN = 1;                                                                   //使能接收
      000A8D D2 C4            [12]  872 	setb	_U1REN
                                    873 ;	../../include/debug.c:270: SBAUD1 = 256 - FREQ_SYS/16/UART1_BUAD;
      000A8F 75 C2 98         [24]  874 	mov	_SBAUD1,#0x98
      000A92 22               [24]  875 	ret
                                    876 ;------------------------------------------------------------
                                    877 ;Allocation info for local variables in function 'CH554UART1RcvByte'
                                    878 ;------------------------------------------------------------
                                    879 ;	../../include/debug.c:280: uint8_t  CH554UART1RcvByte( )
                                    880 ;	-----------------------------------------
                                    881 ;	 function CH554UART1RcvByte
                                    882 ;	-----------------------------------------
      000A93                        883 _CH554UART1RcvByte:
                                    884 ;	../../include/debug.c:282: while(U1RI == 0);                                                           //查询接收，中断方式可不用
      000A93                        885 00101$:
                                    886 ;	../../include/debug.c:283: U1RI = 0;
      000A93 10 C0 02         [24]  887 	jbc	_U1RI,00112$
      000A96 80 FB            [24]  888 	sjmp	00101$
      000A98                        889 00112$:
                                    890 ;	../../include/debug.c:284: return SBUF1;
      000A98 85 C1 82         [24]  891 	mov	dpl,_SBUF1
      000A9B 22               [24]  892 	ret
                                    893 ;------------------------------------------------------------
                                    894 ;Allocation info for local variables in function 'CH554UART1SendByte'
                                    895 ;------------------------------------------------------------
                                    896 ;SendDat                   Allocated to registers 
                                    897 ;------------------------------------------------------------
                                    898 ;	../../include/debug.c:294: void CH554UART1SendByte(uint8_t SendDat)
                                    899 ;	-----------------------------------------
                                    900 ;	 function CH554UART1SendByte
                                    901 ;	-----------------------------------------
      000A9C                        902 _CH554UART1SendByte:
      000A9C 85 82 C1         [24]  903 	mov	_SBUF1,dpl
                                    904 ;	../../include/debug.c:297: while(U1TI ==0);
      000A9F                        905 00101$:
                                    906 ;	../../include/debug.c:298: U1TI = 0;
      000A9F 10 C1 02         [24]  907 	jbc	_U1TI,00112$
      000AA2 80 FB            [24]  908 	sjmp	00101$
      000AA4                        909 00112$:
      000AA4 22               [24]  910 	ret
                                    911 ;------------------------------------------------------------
                                    912 ;Allocation info for local variables in function 'CH554WDTModeSelect'
                                    913 ;------------------------------------------------------------
                                    914 ;mode                      Allocated to registers r7 
                                    915 ;------------------------------------------------------------
                                    916 ;	../../include/debug.c:310: void CH554WDTModeSelect(uint8_t mode)
                                    917 ;	-----------------------------------------
                                    918 ;	 function CH554WDTModeSelect
                                    919 ;	-----------------------------------------
      000AA5                        920 _CH554WDTModeSelect:
      000AA5 AF 82            [24]  921 	mov	r7,dpl
                                    922 ;	../../include/debug.c:312: SAFE_MOD = 0x55;
      000AA7 75 A1 55         [24]  923 	mov	_SAFE_MOD,#0x55
                                    924 ;	../../include/debug.c:313: SAFE_MOD = 0xaa;                                                             //进入安全模式
      000AAA 75 A1 AA         [24]  925 	mov	_SAFE_MOD,#0xaa
                                    926 ;	../../include/debug.c:314: if(mode){
      000AAD EF               [12]  927 	mov	a,r7
      000AAE 60 05            [24]  928 	jz	00102$
                                    929 ;	../../include/debug.c:315: GLOBAL_CFG |= bWDOG_EN;                                                    //启动看门狗复位
      000AB0 43 B1 01         [24]  930 	orl	_GLOBAL_CFG,#0x01
      000AB3 80 03            [24]  931 	sjmp	00103$
      000AB5                        932 00102$:
                                    933 ;	../../include/debug.c:317: else GLOBAL_CFG &= ~bWDOG_EN;	                                            //启动看门狗仅仅作为定时器
      000AB5 53 B1 FE         [24]  934 	anl	_GLOBAL_CFG,#0xfe
      000AB8                        935 00103$:
                                    936 ;	../../include/debug.c:318: SAFE_MOD = 0x00;                                                             //退出安全模式
      000AB8 75 A1 00         [24]  937 	mov	_SAFE_MOD,#0x00
                                    938 ;	../../include/debug.c:319: WDOG_COUNT = 0;                                                              //看门狗赋初值
      000ABB 75 FF 00         [24]  939 	mov	_WDOG_COUNT,#0x00
      000ABE 22               [24]  940 	ret
                                    941 ;------------------------------------------------------------
                                    942 ;Allocation info for local variables in function 'CH554WDTFeed'
                                    943 ;------------------------------------------------------------
                                    944 ;tim                       Allocated to registers 
                                    945 ;------------------------------------------------------------
                                    946 ;	../../include/debug.c:331: void CH554WDTFeed(uint8_t tim)
                                    947 ;	-----------------------------------------
                                    948 ;	 function CH554WDTFeed
                                    949 ;	-----------------------------------------
      000ABF                        950 _CH554WDTFeed:
      000ABF 85 82 FF         [24]  951 	mov	_WDOG_COUNT,dpl
                                    952 ;	../../include/debug.c:333: WDOG_COUNT = tim;                                                             //看门狗计数器赋值
      000AC2 22               [24]  953 	ret
                                    954 	.area CSEG    (CODE)
                                    955 	.area CONST   (CODE)
                                    956 	.area XINIT   (CODE)
                                    957 	.area CABS    (ABS,CODE)
