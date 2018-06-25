                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.6.0 #9615 (MINGW64)
                                      4 ;--------------------------------------------------------
                                      5 	.module main
                                      6 	.optsdcc -mmcs51 --model-small
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _main
                                     12 	.globl _sendGeometryRight
                                     13 	.globl _sendGeometryLeft
                                     14 	.globl _fadeLetters
                                     15 	.globl _fadeLeds
                                     16 	.globl _initBoard
                                     17 	.globl _icn2053_updateDisplay
                                     18 	.globl _icn2053_begin
                                     19 	.globl _UART1_buf_write
                                     20 	.globl _UART1_buf_init
                                     21 	.globl _UART0_buf_write
                                     22 	.globl _UART0_buf_init
                                     23 	.globl _powf
                                     24 	.globl _UART1Setup
                                     25 	.globl _CH554UART1Alter
                                     26 	.globl _mInitSTDIO
                                     27 	.globl _CfgFsys
                                     28 	.globl _BUTTON2
                                     29 	.globl _BUTTON1
                                     30 	.globl _LED_GCLK
                                     31 	.globl _LED_LE
                                     32 	.globl _LED_MOSI
                                     33 	.globl _LED_CLK
                                     34 	.globl _UIF_BUS_RST
                                     35 	.globl _UIF_DETECT
                                     36 	.globl _UIF_TRANSFER
                                     37 	.globl _UIF_SUSPEND
                                     38 	.globl _UIF_HST_SOF
                                     39 	.globl _UIF_FIFO_OV
                                     40 	.globl _U_SIE_FREE
                                     41 	.globl _U_TOG_OK
                                     42 	.globl _U_IS_NAK
                                     43 	.globl _ADC_CHAN0
                                     44 	.globl _ADC_CHAN1
                                     45 	.globl _CMP_CHAN
                                     46 	.globl _ADC_START
                                     47 	.globl _ADC_IF
                                     48 	.globl _CMP_IF
                                     49 	.globl _CMPO
                                     50 	.globl _U1RI
                                     51 	.globl _U1TI
                                     52 	.globl _U1RB8
                                     53 	.globl _U1TB8
                                     54 	.globl _U1REN
                                     55 	.globl _U1SMOD
                                     56 	.globl _U1SM0
                                     57 	.globl _S0_R_FIFO
                                     58 	.globl _S0_T_FIFO
                                     59 	.globl _S0_FREE
                                     60 	.globl _S0_IF_BYTE
                                     61 	.globl _S0_IF_FIRST
                                     62 	.globl _S0_IF_OV
                                     63 	.globl _S0_FST_ACT
                                     64 	.globl _CP_RL2
                                     65 	.globl _C_T2
                                     66 	.globl _TR2
                                     67 	.globl _EXEN2
                                     68 	.globl _TCLK
                                     69 	.globl _RCLK
                                     70 	.globl _EXF2
                                     71 	.globl _CAP1F
                                     72 	.globl _TF2
                                     73 	.globl _RI
                                     74 	.globl _TI
                                     75 	.globl _RB8
                                     76 	.globl _TB8
                                     77 	.globl _REN
                                     78 	.globl _SM2
                                     79 	.globl _SM1
                                     80 	.globl _SM0
                                     81 	.globl _IT0
                                     82 	.globl _IE0
                                     83 	.globl _IT1
                                     84 	.globl _IE1
                                     85 	.globl _TR0
                                     86 	.globl _TF0
                                     87 	.globl _TR1
                                     88 	.globl _TF1
                                     89 	.globl _RXD
                                     90 	.globl _PWM1_
                                     91 	.globl _TXD
                                     92 	.globl _PWM2_
                                     93 	.globl _AIN3
                                     94 	.globl _VBUS1
                                     95 	.globl _INT0
                                     96 	.globl _TXD1_
                                     97 	.globl _INT1
                                     98 	.globl _T0
                                     99 	.globl _RXD1_
                                    100 	.globl _PWM2
                                    101 	.globl _T1
                                    102 	.globl _UDP
                                    103 	.globl _UDM
                                    104 	.globl _TIN0
                                    105 	.globl _CAP1
                                    106 	.globl _T2
                                    107 	.globl _AIN0
                                    108 	.globl _VBUS2
                                    109 	.globl _TIN1
                                    110 	.globl _CAP2
                                    111 	.globl _T2EX
                                    112 	.globl _RXD_
                                    113 	.globl _TXD_
                                    114 	.globl _AIN1
                                    115 	.globl _UCC1
                                    116 	.globl _TIN2
                                    117 	.globl _SCS
                                    118 	.globl _CAP1_
                                    119 	.globl _T2_
                                    120 	.globl _AIN2
                                    121 	.globl _UCC2
                                    122 	.globl _TIN3
                                    123 	.globl _PWM1
                                    124 	.globl _MOSI
                                    125 	.globl _TIN4
                                    126 	.globl _RXD1
                                    127 	.globl _MISO
                                    128 	.globl _TIN5
                                    129 	.globl _TXD1
                                    130 	.globl _SCK
                                    131 	.globl _IE_SPI0
                                    132 	.globl _IE_TKEY
                                    133 	.globl _IE_USB
                                    134 	.globl _IE_ADC
                                    135 	.globl _IE_UART1
                                    136 	.globl _IE_PWMX
                                    137 	.globl _IE_GPIO
                                    138 	.globl _IE_WDOG
                                    139 	.globl _PX0
                                    140 	.globl _PT0
                                    141 	.globl _PX1
                                    142 	.globl _PT1
                                    143 	.globl _PS
                                    144 	.globl _PT2
                                    145 	.globl _PL_FLAG
                                    146 	.globl _PH_FLAG
                                    147 	.globl _EX0
                                    148 	.globl _ET0
                                    149 	.globl _EX1
                                    150 	.globl _ET1
                                    151 	.globl _ES
                                    152 	.globl _ET2
                                    153 	.globl _E_DIS
                                    154 	.globl _EA
                                    155 	.globl _P
                                    156 	.globl _F1
                                    157 	.globl _OV
                                    158 	.globl _RS0
                                    159 	.globl _RS1
                                    160 	.globl _F0
                                    161 	.globl _AC
                                    162 	.globl _CY
                                    163 	.globl _UEP1_DMA_H
                                    164 	.globl _UEP1_DMA_L
                                    165 	.globl _UEP1_DMA
                                    166 	.globl _UEP0_DMA_H
                                    167 	.globl _UEP0_DMA_L
                                    168 	.globl _UEP0_DMA
                                    169 	.globl _UEP2_3_MOD
                                    170 	.globl _UEP4_1_MOD
                                    171 	.globl _UEP3_DMA_H
                                    172 	.globl _UEP3_DMA_L
                                    173 	.globl _UEP3_DMA
                                    174 	.globl _UEP2_DMA_H
                                    175 	.globl _UEP2_DMA_L
                                    176 	.globl _UEP2_DMA
                                    177 	.globl _USB_DEV_AD
                                    178 	.globl _USB_CTRL
                                    179 	.globl _USB_INT_EN
                                    180 	.globl _UEP4_T_LEN
                                    181 	.globl _UEP4_CTRL
                                    182 	.globl _UEP0_T_LEN
                                    183 	.globl _UEP0_CTRL
                                    184 	.globl _USB_RX_LEN
                                    185 	.globl _USB_MIS_ST
                                    186 	.globl _USB_INT_ST
                                    187 	.globl _USB_INT_FG
                                    188 	.globl _UEP3_T_LEN
                                    189 	.globl _UEP3_CTRL
                                    190 	.globl _UEP2_T_LEN
                                    191 	.globl _UEP2_CTRL
                                    192 	.globl _UEP1_T_LEN
                                    193 	.globl _UEP1_CTRL
                                    194 	.globl _UDEV_CTRL
                                    195 	.globl _USB_C_CTRL
                                    196 	.globl _TKEY_DATH
                                    197 	.globl _TKEY_DATL
                                    198 	.globl _TKEY_DAT
                                    199 	.globl _TKEY_CTRL
                                    200 	.globl _ADC_DATA
                                    201 	.globl _ADC_CFG
                                    202 	.globl _ADC_CTRL
                                    203 	.globl _SBAUD1
                                    204 	.globl _SBUF1
                                    205 	.globl _SCON1
                                    206 	.globl _SPI0_SETUP
                                    207 	.globl _SPI0_CK_SE
                                    208 	.globl _SPI0_CTRL
                                    209 	.globl _SPI0_DATA
                                    210 	.globl _SPI0_STAT
                                    211 	.globl _PWM_CK_SE
                                    212 	.globl _PWM_CTRL
                                    213 	.globl _PWM_DATA1
                                    214 	.globl _PWM_DATA2
                                    215 	.globl _T2CAP1H
                                    216 	.globl _T2CAP1L
                                    217 	.globl _T2CAP1
                                    218 	.globl _TH2
                                    219 	.globl _TL2
                                    220 	.globl _T2COUNT
                                    221 	.globl _RCAP2H
                                    222 	.globl _RCAP2L
                                    223 	.globl _RCAP2
                                    224 	.globl _T2MOD
                                    225 	.globl _T2CON
                                    226 	.globl _SBUF
                                    227 	.globl _SCON
                                    228 	.globl _TH1
                                    229 	.globl _TH0
                                    230 	.globl _TL1
                                    231 	.globl _TL0
                                    232 	.globl _TMOD
                                    233 	.globl _TCON
                                    234 	.globl _XBUS_AUX
                                    235 	.globl _PIN_FUNC
                                    236 	.globl _P3_DIR_PU
                                    237 	.globl _P3_MOD_OC
                                    238 	.globl _P3
                                    239 	.globl _P2
                                    240 	.globl _P1_DIR_PU
                                    241 	.globl _P1_MOD_OC
                                    242 	.globl _P1
                                    243 	.globl _ROM_CTRL
                                    244 	.globl _ROM_DATA_H
                                    245 	.globl _ROM_DATA_L
                                    246 	.globl _ROM_DATA
                                    247 	.globl _ROM_ADDR_H
                                    248 	.globl _ROM_ADDR_L
                                    249 	.globl _ROM_ADDR
                                    250 	.globl _GPIO_IE
                                    251 	.globl _IP_EX
                                    252 	.globl _IE_EX
                                    253 	.globl _IP
                                    254 	.globl _IE
                                    255 	.globl _WDOG_COUNT
                                    256 	.globl _RESET_KEEP
                                    257 	.globl _WAKE_CTRL
                                    258 	.globl _CLOCK_CFG
                                    259 	.globl _PCON
                                    260 	.globl _GLOBAL_CFG
                                    261 	.globl _SAFE_MOD
                                    262 	.globl _DPH
                                    263 	.globl _DPL
                                    264 	.globl _SP
                                    265 	.globl _B
                                    266 	.globl _ACC
                                    267 	.globl _PSW
                                    268 	.globl _pattern
                                    269 	.globl _brightness
                                    270 	.globl _ttlRight
                                    271 	.globl _lettersToRight
                                    272 	.globl _ledsToRight
                                    273 	.globl _ttlLeft
                                    274 	.globl _lettersToLeft
                                    275 	.globl _ledsToLeft
                                    276 	.globl _ledData
                                    277 	.globl _bootloader
                                    278 ;--------------------------------------------------------
                                    279 ; special function registers
                                    280 ;--------------------------------------------------------
                                    281 	.area RSEG    (ABS,DATA)
      000000                        282 	.org 0x0000
                           0000D0   283 _PSW	=	0x00d0
                           0000E0   284 _ACC	=	0x00e0
                           0000F0   285 _B	=	0x00f0
                           000081   286 _SP	=	0x0081
                           000082   287 _DPL	=	0x0082
                           000083   288 _DPH	=	0x0083
                           0000A1   289 _SAFE_MOD	=	0x00a1
                           0000B1   290 _GLOBAL_CFG	=	0x00b1
                           000087   291 _PCON	=	0x0087
                           0000B9   292 _CLOCK_CFG	=	0x00b9
                           0000A9   293 _WAKE_CTRL	=	0x00a9
                           0000FE   294 _RESET_KEEP	=	0x00fe
                           0000FF   295 _WDOG_COUNT	=	0x00ff
                           0000A8   296 _IE	=	0x00a8
                           0000B8   297 _IP	=	0x00b8
                           0000E8   298 _IE_EX	=	0x00e8
                           0000E9   299 _IP_EX	=	0x00e9
                           0000C7   300 _GPIO_IE	=	0x00c7
                           008584   301 _ROM_ADDR	=	0x8584
                           000084   302 _ROM_ADDR_L	=	0x0084
                           000085   303 _ROM_ADDR_H	=	0x0085
                           008F8E   304 _ROM_DATA	=	0x8f8e
                           00008E   305 _ROM_DATA_L	=	0x008e
                           00008F   306 _ROM_DATA_H	=	0x008f
                           000086   307 _ROM_CTRL	=	0x0086
                           000090   308 _P1	=	0x0090
                           000092   309 _P1_MOD_OC	=	0x0092
                           000093   310 _P1_DIR_PU	=	0x0093
                           0000A0   311 _P2	=	0x00a0
                           0000B0   312 _P3	=	0x00b0
                           000096   313 _P3_MOD_OC	=	0x0096
                           000097   314 _P3_DIR_PU	=	0x0097
                           0000C6   315 _PIN_FUNC	=	0x00c6
                           0000A2   316 _XBUS_AUX	=	0x00a2
                           000088   317 _TCON	=	0x0088
                           000089   318 _TMOD	=	0x0089
                           00008A   319 _TL0	=	0x008a
                           00008B   320 _TL1	=	0x008b
                           00008C   321 _TH0	=	0x008c
                           00008D   322 _TH1	=	0x008d
                           000098   323 _SCON	=	0x0098
                           000099   324 _SBUF	=	0x0099
                           0000C8   325 _T2CON	=	0x00c8
                           0000C9   326 _T2MOD	=	0x00c9
                           00CBCA   327 _RCAP2	=	0xcbca
                           0000CA   328 _RCAP2L	=	0x00ca
                           0000CB   329 _RCAP2H	=	0x00cb
                           00CDCC   330 _T2COUNT	=	0xcdcc
                           0000CC   331 _TL2	=	0x00cc
                           0000CD   332 _TH2	=	0x00cd
                           00CFCE   333 _T2CAP1	=	0xcfce
                           0000CE   334 _T2CAP1L	=	0x00ce
                           0000CF   335 _T2CAP1H	=	0x00cf
                           00009B   336 _PWM_DATA2	=	0x009b
                           00009C   337 _PWM_DATA1	=	0x009c
                           00009D   338 _PWM_CTRL	=	0x009d
                           00009E   339 _PWM_CK_SE	=	0x009e
                           0000F8   340 _SPI0_STAT	=	0x00f8
                           0000F9   341 _SPI0_DATA	=	0x00f9
                           0000FA   342 _SPI0_CTRL	=	0x00fa
                           0000FB   343 _SPI0_CK_SE	=	0x00fb
                           0000FC   344 _SPI0_SETUP	=	0x00fc
                           0000C0   345 _SCON1	=	0x00c0
                           0000C1   346 _SBUF1	=	0x00c1
                           0000C2   347 _SBAUD1	=	0x00c2
                           000080   348 _ADC_CTRL	=	0x0080
                           00009A   349 _ADC_CFG	=	0x009a
                           00009F   350 _ADC_DATA	=	0x009f
                           0000C3   351 _TKEY_CTRL	=	0x00c3
                           00C5C4   352 _TKEY_DAT	=	0xc5c4
                           0000C4   353 _TKEY_DATL	=	0x00c4
                           0000C5   354 _TKEY_DATH	=	0x00c5
                           000091   355 _USB_C_CTRL	=	0x0091
                           0000D1   356 _UDEV_CTRL	=	0x00d1
                           0000D2   357 _UEP1_CTRL	=	0x00d2
                           0000D3   358 _UEP1_T_LEN	=	0x00d3
                           0000D4   359 _UEP2_CTRL	=	0x00d4
                           0000D5   360 _UEP2_T_LEN	=	0x00d5
                           0000D6   361 _UEP3_CTRL	=	0x00d6
                           0000D7   362 _UEP3_T_LEN	=	0x00d7
                           0000D8   363 _USB_INT_FG	=	0x00d8
                           0000D9   364 _USB_INT_ST	=	0x00d9
                           0000DA   365 _USB_MIS_ST	=	0x00da
                           0000DB   366 _USB_RX_LEN	=	0x00db
                           0000DC   367 _UEP0_CTRL	=	0x00dc
                           0000DD   368 _UEP0_T_LEN	=	0x00dd
                           0000DE   369 _UEP4_CTRL	=	0x00de
                           0000DF   370 _UEP4_T_LEN	=	0x00df
                           0000E1   371 _USB_INT_EN	=	0x00e1
                           0000E2   372 _USB_CTRL	=	0x00e2
                           0000E3   373 _USB_DEV_AD	=	0x00e3
                           00E5E4   374 _UEP2_DMA	=	0xe5e4
                           0000E4   375 _UEP2_DMA_L	=	0x00e4
                           0000E5   376 _UEP2_DMA_H	=	0x00e5
                           00E7E6   377 _UEP3_DMA	=	0xe7e6
                           0000E6   378 _UEP3_DMA_L	=	0x00e6
                           0000E7   379 _UEP3_DMA_H	=	0x00e7
                           0000EA   380 _UEP4_1_MOD	=	0x00ea
                           0000EB   381 _UEP2_3_MOD	=	0x00eb
                           00EDEC   382 _UEP0_DMA	=	0xedec
                           0000EC   383 _UEP0_DMA_L	=	0x00ec
                           0000ED   384 _UEP0_DMA_H	=	0x00ed
                           00EFEE   385 _UEP1_DMA	=	0xefee
                           0000EE   386 _UEP1_DMA_L	=	0x00ee
                           0000EF   387 _UEP1_DMA_H	=	0x00ef
                                    388 ;--------------------------------------------------------
                                    389 ; special function bits
                                    390 ;--------------------------------------------------------
                                    391 	.area RSEG    (ABS,DATA)
      000000                        392 	.org 0x0000
                           0000D7   393 _CY	=	0x00d7
                           0000D6   394 _AC	=	0x00d6
                           0000D5   395 _F0	=	0x00d5
                           0000D4   396 _RS1	=	0x00d4
                           0000D3   397 _RS0	=	0x00d3
                           0000D2   398 _OV	=	0x00d2
                           0000D1   399 _F1	=	0x00d1
                           0000D0   400 _P	=	0x00d0
                           0000AF   401 _EA	=	0x00af
                           0000AE   402 _E_DIS	=	0x00ae
                           0000AD   403 _ET2	=	0x00ad
                           0000AC   404 _ES	=	0x00ac
                           0000AB   405 _ET1	=	0x00ab
                           0000AA   406 _EX1	=	0x00aa
                           0000A9   407 _ET0	=	0x00a9
                           0000A8   408 _EX0	=	0x00a8
                           0000BF   409 _PH_FLAG	=	0x00bf
                           0000BE   410 _PL_FLAG	=	0x00be
                           0000BD   411 _PT2	=	0x00bd
                           0000BC   412 _PS	=	0x00bc
                           0000BB   413 _PT1	=	0x00bb
                           0000BA   414 _PX1	=	0x00ba
                           0000B9   415 _PT0	=	0x00b9
                           0000B8   416 _PX0	=	0x00b8
                           0000EF   417 _IE_WDOG	=	0x00ef
                           0000EE   418 _IE_GPIO	=	0x00ee
                           0000ED   419 _IE_PWMX	=	0x00ed
                           0000EC   420 _IE_UART1	=	0x00ec
                           0000EB   421 _IE_ADC	=	0x00eb
                           0000EA   422 _IE_USB	=	0x00ea
                           0000E9   423 _IE_TKEY	=	0x00e9
                           0000E8   424 _IE_SPI0	=	0x00e8
                           000097   425 _SCK	=	0x0097
                           000097   426 _TXD1	=	0x0097
                           000097   427 _TIN5	=	0x0097
                           000096   428 _MISO	=	0x0096
                           000096   429 _RXD1	=	0x0096
                           000096   430 _TIN4	=	0x0096
                           000095   431 _MOSI	=	0x0095
                           000095   432 _PWM1	=	0x0095
                           000095   433 _TIN3	=	0x0095
                           000095   434 _UCC2	=	0x0095
                           000095   435 _AIN2	=	0x0095
                           000094   436 _T2_	=	0x0094
                           000094   437 _CAP1_	=	0x0094
                           000094   438 _SCS	=	0x0094
                           000094   439 _TIN2	=	0x0094
                           000094   440 _UCC1	=	0x0094
                           000094   441 _AIN1	=	0x0094
                           000093   442 _TXD_	=	0x0093
                           000092   443 _RXD_	=	0x0092
                           000091   444 _T2EX	=	0x0091
                           000091   445 _CAP2	=	0x0091
                           000091   446 _TIN1	=	0x0091
                           000091   447 _VBUS2	=	0x0091
                           000091   448 _AIN0	=	0x0091
                           000090   449 _T2	=	0x0090
                           000090   450 _CAP1	=	0x0090
                           000090   451 _TIN0	=	0x0090
                           0000B7   452 _UDM	=	0x00b7
                           0000B6   453 _UDP	=	0x00b6
                           0000B5   454 _T1	=	0x00b5
                           0000B4   455 _PWM2	=	0x00b4
                           0000B4   456 _RXD1_	=	0x00b4
                           0000B4   457 _T0	=	0x00b4
                           0000B3   458 _INT1	=	0x00b3
                           0000B2   459 _TXD1_	=	0x00b2
                           0000B2   460 _INT0	=	0x00b2
                           0000B2   461 _VBUS1	=	0x00b2
                           0000B2   462 _AIN3	=	0x00b2
                           0000B1   463 _PWM2_	=	0x00b1
                           0000B1   464 _TXD	=	0x00b1
                           0000B0   465 _PWM1_	=	0x00b0
                           0000B0   466 _RXD	=	0x00b0
                           00008F   467 _TF1	=	0x008f
                           00008E   468 _TR1	=	0x008e
                           00008D   469 _TF0	=	0x008d
                           00008C   470 _TR0	=	0x008c
                           00008B   471 _IE1	=	0x008b
                           00008A   472 _IT1	=	0x008a
                           000089   473 _IE0	=	0x0089
                           000088   474 _IT0	=	0x0088
                           00009F   475 _SM0	=	0x009f
                           00009E   476 _SM1	=	0x009e
                           00009D   477 _SM2	=	0x009d
                           00009C   478 _REN	=	0x009c
                           00009B   479 _TB8	=	0x009b
                           00009A   480 _RB8	=	0x009a
                           000099   481 _TI	=	0x0099
                           000098   482 _RI	=	0x0098
                           0000CF   483 _TF2	=	0x00cf
                           0000CF   484 _CAP1F	=	0x00cf
                           0000CE   485 _EXF2	=	0x00ce
                           0000CD   486 _RCLK	=	0x00cd
                           0000CC   487 _TCLK	=	0x00cc
                           0000CB   488 _EXEN2	=	0x00cb
                           0000CA   489 _TR2	=	0x00ca
                           0000C9   490 _C_T2	=	0x00c9
                           0000C8   491 _CP_RL2	=	0x00c8
                           0000FF   492 _S0_FST_ACT	=	0x00ff
                           0000FE   493 _S0_IF_OV	=	0x00fe
                           0000FD   494 _S0_IF_FIRST	=	0x00fd
                           0000FC   495 _S0_IF_BYTE	=	0x00fc
                           0000FB   496 _S0_FREE	=	0x00fb
                           0000FA   497 _S0_T_FIFO	=	0x00fa
                           0000F8   498 _S0_R_FIFO	=	0x00f8
                           0000C7   499 _U1SM0	=	0x00c7
                           0000C5   500 _U1SMOD	=	0x00c5
                           0000C4   501 _U1REN	=	0x00c4
                           0000C3   502 _U1TB8	=	0x00c3
                           0000C2   503 _U1RB8	=	0x00c2
                           0000C1   504 _U1TI	=	0x00c1
                           0000C0   505 _U1RI	=	0x00c0
                           000087   506 _CMPO	=	0x0087
                           000086   507 _CMP_IF	=	0x0086
                           000085   508 _ADC_IF	=	0x0085
                           000084   509 _ADC_START	=	0x0084
                           000083   510 _CMP_CHAN	=	0x0083
                           000081   511 _ADC_CHAN1	=	0x0081
                           000080   512 _ADC_CHAN0	=	0x0080
                           0000DF   513 _U_IS_NAK	=	0x00df
                           0000DE   514 _U_TOG_OK	=	0x00de
                           0000DD   515 _U_SIE_FREE	=	0x00dd
                           0000DC   516 _UIF_FIFO_OV	=	0x00dc
                           0000DB   517 _UIF_HST_SOF	=	0x00db
                           0000DA   518 _UIF_SUSPEND	=	0x00da
                           0000D9   519 _UIF_TRANSFER	=	0x00d9
                           0000D8   520 _UIF_DETECT	=	0x00d8
                           0000D8   521 _UIF_BUS_RST	=	0x00d8
                           000093   522 _LED_CLK	=	0x0093
                           000091   523 _LED_MOSI	=	0x0091
                           000092   524 _LED_LE	=	0x0092
                           000090   525 _LED_GCLK	=	0x0090
                           0000B5   526 _BUTTON1	=	0x00b5
                           0000B3   527 _BUTTON2	=	0x00b3
                                    528 ;--------------------------------------------------------
                                    529 ; overlayable register banks
                                    530 ;--------------------------------------------------------
                                    531 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        532 	.ds 8
                                    533 ;--------------------------------------------------------
                                    534 ; internal ram data
                                    535 ;--------------------------------------------------------
                                    536 	.area DSEG    (DATA)
      000023                        537 _bootloader::
      000023                        538 	.ds 2
      000025                        539 _ledData::
      000025                        540 	.ds 16
      000035                        541 _ledsToLeft::
      000035                        542 	.ds 1
      000036                        543 _lettersToLeft::
      000036                        544 	.ds 1
      000037                        545 _ttlLeft::
      000037                        546 	.ds 1
      000038                        547 _ledsToRight::
      000038                        548 	.ds 1
      000039                        549 _lettersToRight::
      000039                        550 	.ds 1
      00003A                        551 _ttlRight::
      00003A                        552 	.ds 1
      00003B                        553 _brightness::
      00003B                        554 	.ds 1
      00003C                        555 _pattern::
      00003C                        556 	.ds 1
      00003D                        557 _fadeLeds_step_1_60:
      00003D                        558 	.ds 1
      00003E                        559 _fadeLeds_phase_1_60:
      00003E                        560 	.ds 4
      000042                        561 _fadeLetters_step_1_70:
      000042                        562 	.ds 1
      000043                        563 _fadeLetters_phase_1_70:
      000043                        564 	.ds 4
                                    565 ;--------------------------------------------------------
                                    566 ; overlayable items in internal ram 
                                    567 ;--------------------------------------------------------
                                    568 ;--------------------------------------------------------
                                    569 ; Stack segment in internal ram 
                                    570 ;--------------------------------------------------------
                                    571 	.area	SSEG
      00007F                        572 __start__stack:
      00007F                        573 	.ds	1
                                    574 
                                    575 ;--------------------------------------------------------
                                    576 ; indirectly addressable internal ram data
                                    577 ;--------------------------------------------------------
                                    578 	.area ISEG    (DATA)
                                    579 ;--------------------------------------------------------
                                    580 ; absolute internal ram data
                                    581 ;--------------------------------------------------------
                                    582 	.area IABS    (ABS,DATA)
                                    583 	.area IABS    (ABS,DATA)
                                    584 ;--------------------------------------------------------
                                    585 ; bit data
                                    586 ;--------------------------------------------------------
                                    587 	.area BSEG    (BIT)
                                    588 ;--------------------------------------------------------
                                    589 ; paged external ram data
                                    590 ;--------------------------------------------------------
                                    591 	.area PSEG    (PAG,XDATA)
                                    592 ;--------------------------------------------------------
                                    593 ; external ram data
                                    594 ;--------------------------------------------------------
                                    595 	.area XSEG    (XDATA)
                                    596 ;--------------------------------------------------------
                                    597 ; absolute external ram data
                                    598 ;--------------------------------------------------------
                                    599 	.area XABS    (ABS,XDATA)
                                    600 ;--------------------------------------------------------
                                    601 ; external initialized ram data
                                    602 ;--------------------------------------------------------
                                    603 	.area XISEG   (XDATA)
                                    604 	.area HOME    (CODE)
                                    605 	.area GSINIT0 (CODE)
                                    606 	.area GSINIT1 (CODE)
                                    607 	.area GSINIT2 (CODE)
                                    608 	.area GSINIT3 (CODE)
                                    609 	.area GSINIT4 (CODE)
                                    610 	.area GSINIT5 (CODE)
                                    611 	.area GSINIT  (CODE)
                                    612 	.area GSFINAL (CODE)
                                    613 	.area CSEG    (CODE)
                                    614 ;--------------------------------------------------------
                                    615 ; interrupt vector 
                                    616 ;--------------------------------------------------------
                                    617 	.area HOME    (CODE)
      000000                        618 __interrupt_vect:
      000000 02 00 5B         [24]  619 	ljmp	__sdcc_gsinit_startup
      000003 32               [24]  620 	reti
      000004                        621 	.ds	7
      00000B 32               [24]  622 	reti
      00000C                        623 	.ds	7
      000013 32               [24]  624 	reti
      000014                        625 	.ds	7
      00001B 32               [24]  626 	reti
      00001C                        627 	.ds	7
      000023 02 06 7B         [24]  628 	ljmp	_UART0_ISR
      000026                        629 	.ds	5
      00002B 32               [24]  630 	reti
      00002C                        631 	.ds	7
      000033 32               [24]  632 	reti
      000034                        633 	.ds	7
      00003B 32               [24]  634 	reti
      00003C                        635 	.ds	7
      000043 32               [24]  636 	reti
      000044                        637 	.ds	7
      00004B 32               [24]  638 	reti
      00004C                        639 	.ds	7
      000053 02 07 31         [24]  640 	ljmp	_UART1_ISR
                                    641 ;--------------------------------------------------------
                                    642 ; global & static initialisations
                                    643 ;--------------------------------------------------------
                                    644 	.area HOME    (CODE)
                                    645 	.area GSINIT  (CODE)
                                    646 	.area GSFINAL (CODE)
                                    647 	.area GSINIT  (CODE)
                                    648 	.globl __sdcc_gsinit_startup
                                    649 	.globl __sdcc_program_startup
                                    650 	.globl __start__stack
                                    651 	.globl __mcs51_genXINIT
                                    652 	.globl __mcs51_genXRAMCLEAR
                                    653 	.globl __mcs51_genRAMCLEAR
                                    654 ;------------------------------------------------------------
                                    655 ;Allocation info for local variables in function 'fadeLeds'
                                    656 ;------------------------------------------------------------
                                    657 ;step                      Allocated with name '_fadeLeds_step_1_60'
                                    658 ;phase                     Allocated with name '_fadeLeds_phase_1_60'
                                    659 ;i                         Allocated to registers r6 
                                    660 ;brightness                Allocated to registers r7 
                                    661 ;------------------------------------------------------------
                                    662 ;	main.c:100: static uint8_t step = 0;
                                    663 ;	main.c:101: static float phase = 0;
      0000B4 E4               [12]  664 	clr	a
      0000B5 F5 3D            [12]  665 	mov	_fadeLeds_step_1_60,a
      0000B7 F5 3E            [12]  666 	mov	_fadeLeds_phase_1_60,a
      0000B9 F5 3F            [12]  667 	mov	(_fadeLeds_phase_1_60 + 1),a
      0000BB F5 40            [12]  668 	mov	(_fadeLeds_phase_1_60 + 2),a
      0000BD F5 41            [12]  669 	mov	(_fadeLeds_phase_1_60 + 3),a
                                    670 ;------------------------------------------------------------
                                    671 ;Allocation info for local variables in function 'fadeLetters'
                                    672 ;------------------------------------------------------------
                                    673 ;step                      Allocated with name '_fadeLetters_step_1_70'
                                    674 ;phase                     Allocated with name '_fadeLetters_phase_1_70'
                                    675 ;i                         Allocated to registers r6 
                                    676 ;brightness                Allocated to registers r7 
                                    677 ;------------------------------------------------------------
                                    678 ;	main.c:166: static uint8_t step = 0;
                                    679 ;	main.c:167: static float phase = 0;
      0000BF E4               [12]  680 	clr	a
      0000C0 F5 42            [12]  681 	mov	_fadeLetters_step_1_70,a
      0000C2 F5 43            [12]  682 	mov	_fadeLetters_phase_1_70,a
      0000C4 F5 44            [12]  683 	mov	(_fadeLetters_phase_1_70 + 1),a
      0000C6 F5 45            [12]  684 	mov	(_fadeLetters_phase_1_70 + 2),a
      0000C8 F5 46            [12]  685 	mov	(_fadeLetters_phase_1_70 + 3),a
                                    686 ;	../../include/bootloader.h:7: ROM_FUNCTION bootloader = (ROM_FUNCTION)BOOT_ADDR;
      0000CA 75 23 00         [24]  687 	mov	_bootloader,#0x00
      0000CD 75 24 38         [24]  688 	mov	(_bootloader + 1),#0x38
                                    689 	.area GSFINAL (CODE)
      000118 02 00 56         [24]  690 	ljmp	__sdcc_program_startup
                                    691 ;--------------------------------------------------------
                                    692 ; Home
                                    693 ;--------------------------------------------------------
                                    694 	.area HOME    (CODE)
                                    695 	.area HOME    (CODE)
      000056                        696 __sdcc_program_startup:
      000056 02 04 5F         [24]  697 	ljmp	_main
                                    698 ;	return from main will return to caller
                                    699 ;--------------------------------------------------------
                                    700 ; code
                                    701 ;--------------------------------------------------------
                                    702 	.area CSEG    (CODE)
                                    703 ;------------------------------------------------------------
                                    704 ;Allocation info for local variables in function 'initBoard'
                                    705 ;------------------------------------------------------------
                                    706 ;	main.c:40: void initBoard() {
                                    707 ;	-----------------------------------------
                                    708 ;	 function initBoard
                                    709 ;	-----------------------------------------
      00011B                        710 _initBoard:
                           000007   711 	ar7 = 0x07
                           000006   712 	ar6 = 0x06
                           000005   713 	ar5 = 0x05
                           000004   714 	ar4 = 0x04
                           000003   715 	ar3 = 0x03
                           000002   716 	ar2 = 0x02
                           000001   717 	ar1 = 0x01
                           000000   718 	ar0 = 0x00
                                    719 ;	main.c:41: CfgFsys();
      00011B 12 09 8C         [24]  720 	lcall	_CfgFsys
                                    721 ;	main.c:44: mInitSTDIO();
      00011E 12 09 D6         [24]  722 	lcall	_mInitSTDIO
                                    723 ;	main.c:45: UART1Setup();
      000121 12 0A 89         [24]  724 	lcall	_UART1Setup
                                    725 ;	main.c:46: CH554UART1Alter();
      000124 12 0A 85         [24]  726 	lcall	_CH554UART1Alter
                                    727 ;	main.c:48: UART0_buf_init();
      000127 12 06 74         [24]  728 	lcall	_UART0_buf_init
                                    729 ;	main.c:49: UART1_buf_init();
      00012A 12 07 2A         [24]  730 	lcall	_UART1_buf_init
                                    731 ;	main.c:52: RCLK = 0;
      00012D C2 CD            [12]  732 	clr	_RCLK
                                    733 ;	main.c:53: TCLK = 0;
      00012F C2 CC            [12]  734 	clr	_TCLK
                                    735 ;	main.c:55: T2MOD |= bTMR_CLK | bT2_CLK | T2OE;
      000131 43 C9 C2         [24]  736 	orl	_T2MOD,#0xc2
                                    737 ;	main.c:56: RCAP2L = 254; // TODO: Set these to the number of PWM counts in a full cycle, so we can use T2 interrupt to update the display
      000134 75 CA FE         [24]  738 	mov	_RCAP2L,#0xfe
                                    739 ;	main.c:57: RCAP2H = 255;
      000137 75 CB FF         [24]  740 	mov	_RCAP2H,#0xff
                                    741 ;	main.c:58: TL2 = 254;
      00013A 75 CC FE         [24]  742 	mov	_TL2,#0xfe
                                    743 ;	main.c:59: TH2 = 255;
      00013D 75 CD FF         [24]  744 	mov	_TH2,#0xff
                                    745 ;	main.c:62: P1_DIR_PU = 0x0F;   // TODO: Do we need to enable pullups?
      000140 75 93 0F         [24]  746 	mov	_P1_DIR_PU,#0x0f
                                    747 ;	main.c:67: & ~(1<<LED_GCLK_PIN);
      000143 53 92 F0         [24]  748 	anl	_P1_MOD_OC,#0xf0
                                    749 ;	main.c:72: | (1<<LED_GCLK_PIN);
      000146 43 93 0F         [24]  750 	orl	_P1_DIR_PU,#0x0f
                                    751 ;	main.c:84: LED_CLK = 0;
      000149 C2 93            [12]  752 	clr	_LED_CLK
                                    753 ;	main.c:85: LED_MOSI = 0;
      00014B C2 91            [12]  754 	clr	_LED_MOSI
                                    755 ;	main.c:86: LED_LE = 0;
      00014D C2 92            [12]  756 	clr	_LED_LE
                                    757 ;	main.c:88: ledsToLeft = 0;
      00014F 75 35 00         [24]  758 	mov	_ledsToLeft,#0x00
                                    759 ;	main.c:89: lettersToLeft = 0;
      000152 75 36 00         [24]  760 	mov	_lettersToLeft,#0x00
                                    761 ;	main.c:90: ttlLeft = 0;
      000155 75 37 00         [24]  762 	mov	_ttlLeft,#0x00
                                    763 ;	main.c:92: ledsToRight = 0;
      000158 75 38 00         [24]  764 	mov	_ledsToRight,#0x00
                                    765 ;	main.c:93: lettersToRight = 0;
      00015B 75 39 00         [24]  766 	mov	_lettersToRight,#0x00
                                    767 ;	main.c:94: ttlRight = 0;
      00015E 75 3A 00         [24]  768 	mov	_ttlRight,#0x00
                                    769 ;	main.c:96: brightness = 255;
      000161 75 3B FF         [24]  770 	mov	_brightness,#0xff
      000164 22               [24]  771 	ret
                                    772 ;------------------------------------------------------------
                                    773 ;Allocation info for local variables in function 'fadeLeds'
                                    774 ;------------------------------------------------------------
                                    775 ;step                      Allocated with name '_fadeLeds_step_1_60'
                                    776 ;phase                     Allocated with name '_fadeLeds_phase_1_60'
                                    777 ;i                         Allocated to registers r6 
                                    778 ;brightness                Allocated to registers r7 
                                    779 ;------------------------------------------------------------
                                    780 ;	main.c:99: void fadeLeds() {
                                    781 ;	-----------------------------------------
                                    782 ;	 function fadeLeds
                                    783 ;	-----------------------------------------
      000165                        784 _fadeLeds:
                                    785 ;	main.c:107: brightness = 250*powf(phase, 1.8);
      000165 75 6E 66         [24]  786 	mov	_powf_PARM_2,#0x66
      000168 75 6F 66         [24]  787 	mov	(_powf_PARM_2 + 1),#0x66
      00016B 75 70 E6         [24]  788 	mov	(_powf_PARM_2 + 2),#0xe6
      00016E 75 71 3F         [24]  789 	mov	(_powf_PARM_2 + 3),#0x3f
      000171 85 3E 82         [24]  790 	mov	dpl,_fadeLeds_phase_1_60
      000174 85 3F 83         [24]  791 	mov	dph,(_fadeLeds_phase_1_60 + 1)
      000177 85 40 F0         [24]  792 	mov	b,(_fadeLeds_phase_1_60 + 2)
      00017A E5 41            [12]  793 	mov	a,(_fadeLeds_phase_1_60 + 3)
      00017C 12 0C FA         [24]  794 	lcall	_powf
      00017F AC 82            [24]  795 	mov	r4,dpl
      000181 AD 83            [24]  796 	mov	r5,dph
      000183 AE F0            [24]  797 	mov	r6,b
      000185 FF               [12]  798 	mov	r7,a
      000186 C0 04            [24]  799 	push	ar4
      000188 C0 05            [24]  800 	push	ar5
      00018A C0 06            [24]  801 	push	ar6
      00018C C0 07            [24]  802 	push	ar7
      00018E 90 00 00         [24]  803 	mov	dptr,#0x0000
      000191 75 F0 7A         [24]  804 	mov	b,#0x7a
      000194 74 43            [12]  805 	mov	a,#0x43
      000196 12 0B 46         [24]  806 	lcall	___fsmul
      000199 AC 82            [24]  807 	mov	r4,dpl
      00019B AD 83            [24]  808 	mov	r5,dph
      00019D AE F0            [24]  809 	mov	r6,b
      00019F FF               [12]  810 	mov	r7,a
      0001A0 E5 81            [12]  811 	mov	a,sp
      0001A2 24 FC            [12]  812 	add	a,#0xfc
      0001A4 F5 81            [12]  813 	mov	sp,a
      0001A6 8C 82            [24]  814 	mov	dpl,r4
      0001A8 8D 83            [24]  815 	mov	dph,r5
      0001AA 8E F0            [24]  816 	mov	b,r6
      0001AC EF               [12]  817 	mov	a,r7
      0001AD 12 0E F4         [24]  818 	lcall	___fs2uchar
      0001B0 AF 82            [24]  819 	mov	r7,dpl
                                    820 ;	main.c:109: for(i = 0; i < LED_COUNT; i++) {
      0001B2 7E 00            [12]  821 	mov	r6,#0x00
      0001B4                        822 00152$:
                                    823 ;	main.c:110: if (step == 0) {
      0001B4 E5 3D            [12]  824 	mov	a,_fadeLeds_step_1_60
      0001B6 70 14            [24]  825 	jnz	00106$
                                    826 ;	main.c:111: if(i==0 || i == 14)
      0001B8 EE               [12]  827 	mov	a,r6
      0001B9 60 03            [24]  828 	jz	00101$
      0001BB BE 0E 08         [24]  829 	cjne	r6,#0x0e,00102$
      0001BE                        830 00101$:
                                    831 ;	main.c:112: ledData[i] = brightness;
      0001BE EE               [12]  832 	mov	a,r6
      0001BF 24 25            [12]  833 	add	a,#_ledData
      0001C1 F8               [12]  834 	mov	r0,a
      0001C2 A6 07            [24]  835 	mov	@r0,ar7
      0001C4 80 06            [24]  836 	sjmp	00106$
      0001C6                        837 00102$:
                                    838 ;	main.c:114: ledData[i] = 0;
      0001C6 EE               [12]  839 	mov	a,r6
      0001C7 24 25            [12]  840 	add	a,#_ledData
      0001C9 F8               [12]  841 	mov	r0,a
      0001CA 76 00            [12]  842 	mov	@r0,#0x00
      0001CC                        843 00106$:
                                    844 ;	main.c:116: if (step == 1) {
      0001CC 74 01            [12]  845 	mov	a,#0x01
      0001CE B5 3D 16         [24]  846 	cjne	a,_fadeLeds_step_1_60,00112$
                                    847 ;	main.c:117: if(i == 1 || i == 13)
      0001D1 BE 01 02         [24]  848 	cjne	r6,#0x01,00217$
      0001D4 80 03            [24]  849 	sjmp	00107$
      0001D6                        850 00217$:
      0001D6 BE 0D 08         [24]  851 	cjne	r6,#0x0d,00108$
      0001D9                        852 00107$:
                                    853 ;	main.c:118: ledData[i] = brightness;
      0001D9 EE               [12]  854 	mov	a,r6
      0001DA 24 25            [12]  855 	add	a,#_ledData
      0001DC F8               [12]  856 	mov	r0,a
      0001DD A6 07            [24]  857 	mov	@r0,ar7
      0001DF 80 06            [24]  858 	sjmp	00112$
      0001E1                        859 00108$:
                                    860 ;	main.c:120: ledData[i] = 0;
      0001E1 EE               [12]  861 	mov	a,r6
      0001E2 24 25            [12]  862 	add	a,#_ledData
      0001E4 F8               [12]  863 	mov	r0,a
      0001E5 76 00            [12]  864 	mov	@r0,#0x00
      0001E7                        865 00112$:
                                    866 ;	main.c:122: if (step == 2) {
      0001E7 74 02            [12]  867 	mov	a,#0x02
      0001E9 B5 3D 1A         [24]  868 	cjne	a,_fadeLeds_step_1_60,00145$
                                    869 ;	main.c:123: if(i == 2 || i == 12)
      0001EC BE 02 02         [24]  870 	cjne	r6,#0x02,00222$
      0001EF 80 03            [24]  871 	sjmp	00113$
      0001F1                        872 00222$:
      0001F1 BE 0C 09         [24]  873 	cjne	r6,#0x0c,00114$
      0001F4                        874 00113$:
                                    875 ;	main.c:124: ledData[i] = brightness;
      0001F4 EE               [12]  876 	mov	a,r6
      0001F5 24 25            [12]  877 	add	a,#_ledData
      0001F7 F8               [12]  878 	mov	r0,a
      0001F8 A6 07            [24]  879 	mov	@r0,ar7
      0001FA 02 02 7A         [24]  880 	ljmp	00153$
      0001FD                        881 00114$:
                                    882 ;	main.c:126: ledData[i] = 0;
      0001FD EE               [12]  883 	mov	a,r6
      0001FE 24 25            [12]  884 	add	a,#_ledData
      000200 F8               [12]  885 	mov	r0,a
      000201 76 00            [12]  886 	mov	@r0,#0x00
      000203 02 02 7A         [24]  887 	ljmp	00153$
      000206                        888 00145$:
                                    889 ;	main.c:128: else if(step == 3) {
      000206 74 03            [12]  890 	mov	a,#0x03
      000208 B5 3D 1A         [24]  891 	cjne	a,_fadeLeds_step_1_60,00142$
                                    892 ;	main.c:129: if(i==3 || i == 11)
      00020B BE 03 02         [24]  893 	cjne	r6,#0x03,00227$
      00020E 80 03            [24]  894 	sjmp	00117$
      000210                        895 00227$:
      000210 BE 0B 09         [24]  896 	cjne	r6,#0x0b,00118$
      000213                        897 00117$:
                                    898 ;	main.c:130: ledData[i] = brightness;
      000213 EE               [12]  899 	mov	a,r6
      000214 24 25            [12]  900 	add	a,#_ledData
      000216 F8               [12]  901 	mov	r0,a
      000217 A6 07            [24]  902 	mov	@r0,ar7
      000219 02 02 7A         [24]  903 	ljmp	00153$
      00021C                        904 00118$:
                                    905 ;	main.c:132: ledData[i] = 0;
      00021C EE               [12]  906 	mov	a,r6
      00021D 24 25            [12]  907 	add	a,#_ledData
      00021F F8               [12]  908 	mov	r0,a
      000220 76 00            [12]  909 	mov	@r0,#0x00
      000222 02 02 7A         [24]  910 	ljmp	00153$
      000225                        911 00142$:
                                    912 ;	main.c:134: else if(step == 4) {
      000225 74 04            [12]  913 	mov	a,#0x04
      000227 B5 3D 18         [24]  914 	cjne	a,_fadeLeds_step_1_60,00139$
                                    915 ;	main.c:135: if(i==4 || i == 10)
      00022A BE 04 02         [24]  916 	cjne	r6,#0x04,00232$
      00022D 80 03            [24]  917 	sjmp	00121$
      00022F                        918 00232$:
      00022F BE 0A 08         [24]  919 	cjne	r6,#0x0a,00122$
      000232                        920 00121$:
                                    921 ;	main.c:136: ledData[i] = brightness;
      000232 EE               [12]  922 	mov	a,r6
      000233 24 25            [12]  923 	add	a,#_ledData
      000235 F8               [12]  924 	mov	r0,a
      000236 A6 07            [24]  925 	mov	@r0,ar7
      000238 80 40            [24]  926 	sjmp	00153$
      00023A                        927 00122$:
                                    928 ;	main.c:138: ledData[i] = 0;
      00023A EE               [12]  929 	mov	a,r6
      00023B 24 25            [12]  930 	add	a,#_ledData
      00023D F8               [12]  931 	mov	r0,a
      00023E 76 00            [12]  932 	mov	@r0,#0x00
      000240 80 38            [24]  933 	sjmp	00153$
      000242                        934 00139$:
                                    935 ;	main.c:140: else if(step == 5) {
      000242 74 05            [12]  936 	mov	a,#0x05
      000244 B5 3D 18         [24]  937 	cjne	a,_fadeLeds_step_1_60,00136$
                                    938 ;	main.c:141: if(i == 5 || i == 9)
      000247 BE 05 02         [24]  939 	cjne	r6,#0x05,00237$
      00024A 80 03            [24]  940 	sjmp	00125$
      00024C                        941 00237$:
      00024C BE 09 08         [24]  942 	cjne	r6,#0x09,00126$
      00024F                        943 00125$:
                                    944 ;	main.c:142: ledData[i] = brightness;
      00024F EE               [12]  945 	mov	a,r6
      000250 24 25            [12]  946 	add	a,#_ledData
      000252 F8               [12]  947 	mov	r0,a
      000253 A6 07            [24]  948 	mov	@r0,ar7
      000255 80 23            [24]  949 	sjmp	00153$
      000257                        950 00126$:
                                    951 ;	main.c:144: ledData[i] = 0;
      000257 EE               [12]  952 	mov	a,r6
      000258 24 25            [12]  953 	add	a,#_ledData
      00025A F8               [12]  954 	mov	r0,a
      00025B 76 00            [12]  955 	mov	@r0,#0x00
      00025D 80 1B            [24]  956 	sjmp	00153$
      00025F                        957 00136$:
                                    958 ;	main.c:146: else if(step == 6) {
      00025F 74 06            [12]  959 	mov	a,#0x06
      000261 B5 3D 16         [24]  960 	cjne	a,_fadeLeds_step_1_60,00153$
                                    961 ;	main.c:147: if(i == 6 || i == 8)
      000264 BE 06 02         [24]  962 	cjne	r6,#0x06,00242$
      000267 80 03            [24]  963 	sjmp	00129$
      000269                        964 00242$:
      000269 BE 08 08         [24]  965 	cjne	r6,#0x08,00130$
      00026C                        966 00129$:
                                    967 ;	main.c:148: ledData[i] = brightness;
      00026C EE               [12]  968 	mov	a,r6
      00026D 24 25            [12]  969 	add	a,#_ledData
      00026F F8               [12]  970 	mov	r0,a
      000270 A6 07            [24]  971 	mov	@r0,ar7
      000272 80 06            [24]  972 	sjmp	00153$
      000274                        973 00130$:
                                    974 ;	main.c:150: ledData[i] = 0;
      000274 EE               [12]  975 	mov	a,r6
      000275 24 25            [12]  976 	add	a,#_ledData
      000277 F8               [12]  977 	mov	r0,a
      000278 76 00            [12]  978 	mov	@r0,#0x00
      00027A                        979 00153$:
                                    980 ;	main.c:109: for(i = 0; i < LED_COUNT; i++) {
      00027A 0E               [12]  981 	inc	r6
      00027B BE 10 00         [24]  982 	cjne	r6,#0x10,00245$
      00027E                        983 00245$:
      00027E 50 03            [24]  984 	jnc	00246$
      000280 02 01 B4         [24]  985 	ljmp	00152$
      000283                        986 00246$:
                                    987 ;	main.c:154: phase += .001;
      000283 74 6F            [12]  988 	mov	a,#0x6f
      000285 C0 E0            [24]  989 	push	acc
      000287 74 12            [12]  990 	mov	a,#0x12
      000289 C0 E0            [24]  991 	push	acc
      00028B 74 83            [12]  992 	mov	a,#0x83
      00028D C0 E0            [24]  993 	push	acc
      00028F 74 3A            [12]  994 	mov	a,#0x3a
      000291 C0 E0            [24]  995 	push	acc
      000293 85 3E 82         [24]  996 	mov	dpl,_fadeLeds_phase_1_60
      000296 85 3F 83         [24]  997 	mov	dph,(_fadeLeds_phase_1_60 + 1)
      000299 85 40 F0         [24]  998 	mov	b,(_fadeLeds_phase_1_60 + 2)
      00029C E5 41            [12]  999 	mov	a,(_fadeLeds_phase_1_60 + 3)
      00029E 12 0D CD         [24] 1000 	lcall	___fsadd
      0002A1 85 82 3E         [24] 1001 	mov	_fadeLeds_phase_1_60,dpl
      0002A4 85 83 3F         [24] 1002 	mov	(_fadeLeds_phase_1_60 + 1),dph
      0002A7 85 F0 40         [24] 1003 	mov	(_fadeLeds_phase_1_60 + 2),b
      0002AA F5 41            [12] 1004 	mov	(_fadeLeds_phase_1_60 + 3),a
      0002AC E5 81            [12] 1005 	mov	a,sp
      0002AE 24 FC            [12] 1006 	add	a,#0xfc
      0002B0 F5 81            [12] 1007 	mov	sp,a
                                   1008 ;	main.c:155: if(phase > 1.0) {
      0002B2 E4               [12] 1009 	clr	a
      0002B3 C0 E0            [24] 1010 	push	acc
      0002B5 C0 E0            [24] 1011 	push	acc
      0002B7 74 80            [12] 1012 	mov	a,#0x80
      0002B9 C0 E0            [24] 1013 	push	acc
      0002BB 74 3F            [12] 1014 	mov	a,#0x3f
      0002BD C0 E0            [24] 1015 	push	acc
      0002BF 85 3E 82         [24] 1016 	mov	dpl,_fadeLeds_phase_1_60
      0002C2 85 3F 83         [24] 1017 	mov	dph,(_fadeLeds_phase_1_60 + 1)
      0002C5 85 40 F0         [24] 1018 	mov	b,(_fadeLeds_phase_1_60 + 2)
      0002C8 E5 41            [12] 1019 	mov	a,(_fadeLeds_phase_1_60 + 3)
      0002CA 12 0C AF         [24] 1020 	lcall	___fsgt
      0002CD AF 82            [24] 1021 	mov	r7,dpl
      0002CF E5 81            [12] 1022 	mov	a,sp
      0002D1 24 FC            [12] 1023 	add	a,#0xfc
      0002D3 F5 81            [12] 1024 	mov	sp,a
      0002D5 EF               [12] 1025 	mov	a,r7
      0002D6 60 14            [24] 1026 	jz	00154$
                                   1027 ;	main.c:156: phase = 0.0;
      0002D8 E4               [12] 1028 	clr	a
      0002D9 F5 3E            [12] 1029 	mov	_fadeLeds_phase_1_60,a
      0002DB F5 3F            [12] 1030 	mov	(_fadeLeds_phase_1_60 + 1),a
      0002DD F5 40            [12] 1031 	mov	(_fadeLeds_phase_1_60 + 2),a
      0002DF F5 41            [12] 1032 	mov	(_fadeLeds_phase_1_60 + 3),a
                                   1033 ;	main.c:158: step = step + 1;
      0002E1 05 3D            [12] 1034 	inc	_fadeLeds_step_1_60
                                   1035 ;	main.c:159: if(step > 7)
      0002E3 E5 3D            [12] 1036 	mov	a,_fadeLeds_step_1_60
      0002E5 24 F8            [12] 1037 	add	a,#0xff - 0x07
      0002E7 50 03            [24] 1038 	jnc	00154$
                                   1039 ;	main.c:160: step = 0;
      0002E9 75 3D 00         [24] 1040 	mov	_fadeLeds_step_1_60,#0x00
      0002EC                       1041 00154$:
      0002EC 22               [24] 1042 	ret
                                   1043 ;------------------------------------------------------------
                                   1044 ;Allocation info for local variables in function 'fadeLetters'
                                   1045 ;------------------------------------------------------------
                                   1046 ;step                      Allocated with name '_fadeLetters_step_1_70'
                                   1047 ;phase                     Allocated with name '_fadeLetters_phase_1_70'
                                   1048 ;i                         Allocated to registers r6 
                                   1049 ;brightness                Allocated to registers r7 
                                   1050 ;------------------------------------------------------------
                                   1051 ;	main.c:165: void fadeLetters() {
                                   1052 ;	-----------------------------------------
                                   1053 ;	 function fadeLetters
                                   1054 ;	-----------------------------------------
      0002ED                       1055 _fadeLetters:
                                   1056 ;	main.c:173: brightness = 250*powf(phase, 1.8);
      0002ED 75 6E 66         [24] 1057 	mov	_powf_PARM_2,#0x66
      0002F0 75 6F 66         [24] 1058 	mov	(_powf_PARM_2 + 1),#0x66
      0002F3 75 70 E6         [24] 1059 	mov	(_powf_PARM_2 + 2),#0xe6
      0002F6 75 71 3F         [24] 1060 	mov	(_powf_PARM_2 + 3),#0x3f
      0002F9 85 43 82         [24] 1061 	mov	dpl,_fadeLetters_phase_1_70
      0002FC 85 44 83         [24] 1062 	mov	dph,(_fadeLetters_phase_1_70 + 1)
      0002FF 85 45 F0         [24] 1063 	mov	b,(_fadeLetters_phase_1_70 + 2)
      000302 E5 46            [12] 1064 	mov	a,(_fadeLetters_phase_1_70 + 3)
      000304 12 0C FA         [24] 1065 	lcall	_powf
      000307 AC 82            [24] 1066 	mov	r4,dpl
      000309 AD 83            [24] 1067 	mov	r5,dph
      00030B AE F0            [24] 1068 	mov	r6,b
      00030D FF               [12] 1069 	mov	r7,a
      00030E C0 04            [24] 1070 	push	ar4
      000310 C0 05            [24] 1071 	push	ar5
      000312 C0 06            [24] 1072 	push	ar6
      000314 C0 07            [24] 1073 	push	ar7
      000316 90 00 00         [24] 1074 	mov	dptr,#0x0000
      000319 75 F0 7A         [24] 1075 	mov	b,#0x7a
      00031C 74 43            [12] 1076 	mov	a,#0x43
      00031E 12 0B 46         [24] 1077 	lcall	___fsmul
      000321 AC 82            [24] 1078 	mov	r4,dpl
      000323 AD 83            [24] 1079 	mov	r5,dph
      000325 AE F0            [24] 1080 	mov	r6,b
      000327 FF               [12] 1081 	mov	r7,a
      000328 E5 81            [12] 1082 	mov	a,sp
      00032A 24 FC            [12] 1083 	add	a,#0xfc
      00032C F5 81            [12] 1084 	mov	sp,a
      00032E 8C 82            [24] 1085 	mov	dpl,r4
      000330 8D 83            [24] 1086 	mov	dph,r5
      000332 8E F0            [24] 1087 	mov	b,r6
      000334 EF               [12] 1088 	mov	a,r7
      000335 12 0E F4         [24] 1089 	lcall	___fs2uchar
      000338 AF 82            [24] 1090 	mov	r7,dpl
                                   1091 ;	main.c:175: for(i = 0; i < LED_COUNT; i++) {
      00033A 7E 00            [12] 1092 	mov	r6,#0x00
      00033C                       1093 00134$:
                                   1094 ;	main.c:176: if (step == 0) {
      00033C E5 42            [12] 1095 	mov	a,_fadeLetters_step_1_70
      00033E 70 2A            [24] 1096 	jnz	00127$
                                   1097 ;	main.c:177: if(i==0 || i == 1 || i == 2 || i == 12 || i == 13 || i == 14)
      000340 EE               [12] 1098 	mov	a,r6
      000341 60 17            [24] 1099 	jz	00101$
      000343 BE 01 02         [24] 1100 	cjne	r6,#0x01,00195$
      000346 80 12            [24] 1101 	sjmp	00101$
      000348                       1102 00195$:
      000348 BE 02 02         [24] 1103 	cjne	r6,#0x02,00196$
      00034B 80 0D            [24] 1104 	sjmp	00101$
      00034D                       1105 00196$:
      00034D BE 0C 02         [24] 1106 	cjne	r6,#0x0c,00197$
      000350 80 08            [24] 1107 	sjmp	00101$
      000352                       1108 00197$:
      000352 BE 0D 02         [24] 1109 	cjne	r6,#0x0d,00198$
      000355 80 03            [24] 1110 	sjmp	00101$
      000357                       1111 00198$:
      000357 BE 0E 08         [24] 1112 	cjne	r6,#0x0e,00102$
      00035A                       1113 00101$:
                                   1114 ;	main.c:178: ledData[i] = brightness;
      00035A EE               [12] 1115 	mov	a,r6
      00035B 24 25            [12] 1116 	add	a,#_ledData
      00035D F8               [12] 1117 	mov	r0,a
      00035E A6 07            [24] 1118 	mov	@r0,ar7
      000360 80 54            [24] 1119 	sjmp	00135$
      000362                       1120 00102$:
                                   1121 ;	main.c:180: ledData[i] = 0;
      000362 EE               [12] 1122 	mov	a,r6
      000363 24 25            [12] 1123 	add	a,#_ledData
      000365 F8               [12] 1124 	mov	r0,a
      000366 76 00            [12] 1125 	mov	@r0,#0x00
      000368 80 4C            [24] 1126 	sjmp	00135$
      00036A                       1127 00127$:
                                   1128 ;	main.c:182: else if(step == 1) {
      00036A 74 01            [12] 1129 	mov	a,#0x01
      00036C B5 42 18         [24] 1130 	cjne	a,_fadeLetters_step_1_70,00124$
                                   1131 ;	main.c:183: if(i==3 || i == 11)
      00036F BE 03 02         [24] 1132 	cjne	r6,#0x03,00203$
      000372 80 03            [24] 1133 	sjmp	00109$
      000374                       1134 00203$:
      000374 BE 0B 08         [24] 1135 	cjne	r6,#0x0b,00110$
      000377                       1136 00109$:
                                   1137 ;	main.c:184: ledData[i] = brightness;
      000377 EE               [12] 1138 	mov	a,r6
      000378 24 25            [12] 1139 	add	a,#_ledData
      00037A F8               [12] 1140 	mov	r0,a
      00037B A6 07            [24] 1141 	mov	@r0,ar7
      00037D 80 37            [24] 1142 	sjmp	00135$
      00037F                       1143 00110$:
                                   1144 ;	main.c:186: ledData[i] = 0;
      00037F EE               [12] 1145 	mov	a,r6
      000380 24 25            [12] 1146 	add	a,#_ledData
      000382 F8               [12] 1147 	mov	r0,a
      000383 76 00            [12] 1148 	mov	@r0,#0x00
      000385 80 2F            [24] 1149 	sjmp	00135$
      000387                       1150 00124$:
                                   1151 ;	main.c:188: else if(step == 2) {
      000387 74 02            [12] 1152 	mov	a,#0x02
      000389 B5 42 2A         [24] 1153 	cjne	a,_fadeLetters_step_1_70,00135$
                                   1154 ;	main.c:189: if(i==4 || i == 5 || i == 6 || i == 8 || i == 9 || i == 10)
      00038C BE 04 02         [24] 1155 	cjne	r6,#0x04,00208$
      00038F 80 17            [24] 1156 	sjmp	00113$
      000391                       1157 00208$:
      000391 BE 05 02         [24] 1158 	cjne	r6,#0x05,00209$
      000394 80 12            [24] 1159 	sjmp	00113$
      000396                       1160 00209$:
      000396 BE 06 02         [24] 1161 	cjne	r6,#0x06,00210$
      000399 80 0D            [24] 1162 	sjmp	00113$
      00039B                       1163 00210$:
      00039B BE 08 02         [24] 1164 	cjne	r6,#0x08,00211$
      00039E 80 08            [24] 1165 	sjmp	00113$
      0003A0                       1166 00211$:
      0003A0 BE 09 02         [24] 1167 	cjne	r6,#0x09,00212$
      0003A3 80 03            [24] 1168 	sjmp	00113$
      0003A5                       1169 00212$:
      0003A5 BE 0A 08         [24] 1170 	cjne	r6,#0x0a,00114$
      0003A8                       1171 00113$:
                                   1172 ;	main.c:190: ledData[i] = brightness;
      0003A8 EE               [12] 1173 	mov	a,r6
      0003A9 24 25            [12] 1174 	add	a,#_ledData
      0003AB F8               [12] 1175 	mov	r0,a
      0003AC A6 07            [24] 1176 	mov	@r0,ar7
      0003AE 80 06            [24] 1177 	sjmp	00135$
      0003B0                       1178 00114$:
                                   1179 ;	main.c:192: ledData[i] = 0;
      0003B0 EE               [12] 1180 	mov	a,r6
      0003B1 24 25            [12] 1181 	add	a,#_ledData
      0003B3 F8               [12] 1182 	mov	r0,a
      0003B4 76 00            [12] 1183 	mov	@r0,#0x00
      0003B6                       1184 00135$:
                                   1185 ;	main.c:175: for(i = 0; i < LED_COUNT; i++) {
      0003B6 0E               [12] 1186 	inc	r6
      0003B7 BE 10 00         [24] 1187 	cjne	r6,#0x10,00215$
      0003BA                       1188 00215$:
      0003BA 50 03            [24] 1189 	jnc	00216$
      0003BC 02 03 3C         [24] 1190 	ljmp	00134$
      0003BF                       1191 00216$:
                                   1192 ;	main.c:196: phase += .001;
      0003BF 74 6F            [12] 1193 	mov	a,#0x6f
      0003C1 C0 E0            [24] 1194 	push	acc
      0003C3 74 12            [12] 1195 	mov	a,#0x12
      0003C5 C0 E0            [24] 1196 	push	acc
      0003C7 74 83            [12] 1197 	mov	a,#0x83
      0003C9 C0 E0            [24] 1198 	push	acc
      0003CB 74 3A            [12] 1199 	mov	a,#0x3a
      0003CD C0 E0            [24] 1200 	push	acc
      0003CF 85 43 82         [24] 1201 	mov	dpl,_fadeLetters_phase_1_70
      0003D2 85 44 83         [24] 1202 	mov	dph,(_fadeLetters_phase_1_70 + 1)
      0003D5 85 45 F0         [24] 1203 	mov	b,(_fadeLetters_phase_1_70 + 2)
      0003D8 E5 46            [12] 1204 	mov	a,(_fadeLetters_phase_1_70 + 3)
      0003DA 12 0D CD         [24] 1205 	lcall	___fsadd
      0003DD 85 82 43         [24] 1206 	mov	_fadeLetters_phase_1_70,dpl
      0003E0 85 83 44         [24] 1207 	mov	(_fadeLetters_phase_1_70 + 1),dph
      0003E3 85 F0 45         [24] 1208 	mov	(_fadeLetters_phase_1_70 + 2),b
      0003E6 F5 46            [12] 1209 	mov	(_fadeLetters_phase_1_70 + 3),a
      0003E8 E5 81            [12] 1210 	mov	a,sp
      0003EA 24 FC            [12] 1211 	add	a,#0xfc
      0003EC F5 81            [12] 1212 	mov	sp,a
                                   1213 ;	main.c:197: if(phase > 1.0) {
      0003EE E4               [12] 1214 	clr	a
      0003EF C0 E0            [24] 1215 	push	acc
      0003F1 C0 E0            [24] 1216 	push	acc
      0003F3 74 80            [12] 1217 	mov	a,#0x80
      0003F5 C0 E0            [24] 1218 	push	acc
      0003F7 74 3F            [12] 1219 	mov	a,#0x3f
      0003F9 C0 E0            [24] 1220 	push	acc
      0003FB 85 43 82         [24] 1221 	mov	dpl,_fadeLetters_phase_1_70
      0003FE 85 44 83         [24] 1222 	mov	dph,(_fadeLetters_phase_1_70 + 1)
      000401 85 45 F0         [24] 1223 	mov	b,(_fadeLetters_phase_1_70 + 2)
      000404 E5 46            [12] 1224 	mov	a,(_fadeLetters_phase_1_70 + 3)
      000406 12 0C AF         [24] 1225 	lcall	___fsgt
      000409 AF 82            [24] 1226 	mov	r7,dpl
      00040B E5 81            [12] 1227 	mov	a,sp
      00040D 24 FC            [12] 1228 	add	a,#0xfc
      00040F F5 81            [12] 1229 	mov	sp,a
      000411 EF               [12] 1230 	mov	a,r7
      000412 60 14            [24] 1231 	jz	00136$
                                   1232 ;	main.c:198: phase = 0.0;
      000414 E4               [12] 1233 	clr	a
      000415 F5 43            [12] 1234 	mov	_fadeLetters_phase_1_70,a
      000417 F5 44            [12] 1235 	mov	(_fadeLetters_phase_1_70 + 1),a
      000419 F5 45            [12] 1236 	mov	(_fadeLetters_phase_1_70 + 2),a
      00041B F5 46            [12] 1237 	mov	(_fadeLetters_phase_1_70 + 3),a
                                   1238 ;	main.c:200: step = step + 1;
      00041D 05 42            [12] 1239 	inc	_fadeLetters_step_1_70
                                   1240 ;	main.c:201: if(step > 2)
      00041F E5 42            [12] 1241 	mov	a,_fadeLetters_step_1_70
      000421 24 FD            [12] 1242 	add	a,#0xff - 0x02
      000423 50 03            [24] 1243 	jnc	00136$
                                   1244 ;	main.c:202: step = 0;
      000425 75 42 00         [24] 1245 	mov	_fadeLetters_step_1_70,#0x00
      000428                       1246 00136$:
      000428 22               [24] 1247 	ret
                                   1248 ;------------------------------------------------------------
                                   1249 ;Allocation info for local variables in function 'sendGeometryLeft'
                                   1250 ;------------------------------------------------------------
                                   1251 ;	main.c:207: void sendGeometryLeft() {
                                   1252 ;	-----------------------------------------
                                   1253 ;	 function sendGeometryLeft
                                   1254 ;	-----------------------------------------
      000429                       1255 _sendGeometryLeft:
                                   1256 ;	main.c:209: UART1_buf_write(RIGHT_GEOMETRY_HEADER);
      000429 75 82 02         [24] 1257 	mov	dpl,#0x02
      00042C 12 07 BF         [24] 1258 	lcall	_UART1_buf_write
                                   1259 ;	main.c:210: UART1_buf_write(lettersToRight + LED_COUNT);
      00042F 74 10            [12] 1260 	mov	a,#0x10
      000431 25 39            [12] 1261 	add	a,_lettersToRight
      000433 F5 82            [12] 1262 	mov	dpl,a
      000435 12 07 BF         [24] 1263 	lcall	_UART1_buf_write
                                   1264 ;	main.c:211: UART1_buf_write(lettersToRight + LETTER_COUNT);
      000438 74 03            [12] 1265 	mov	a,#0x03
      00043A 25 39            [12] 1266 	add	a,_lettersToRight
      00043C F5 82            [12] 1267 	mov	dpl,a
      00043E 02 07 BF         [24] 1268 	ljmp	_UART1_buf_write
                                   1269 ;------------------------------------------------------------
                                   1270 ;Allocation info for local variables in function 'sendGeometryRight'
                                   1271 ;------------------------------------------------------------
                                   1272 ;	main.c:215: void sendGeometryRight() {
                                   1273 ;	-----------------------------------------
                                   1274 ;	 function sendGeometryRight
                                   1275 ;	-----------------------------------------
      000441                       1276 _sendGeometryRight:
                                   1277 ;	main.c:217: UART0_buf_write(LEFT_GEOMETRY_HEADER);
      000441 75 82 01         [24] 1278 	mov	dpl,#0x01
      000444 12 07 09         [24] 1279 	lcall	_UART0_buf_write
                                   1280 ;	main.c:218: UART0_buf_write(lettersToLeft + LED_COUNT);
      000447 74 10            [12] 1281 	mov	a,#0x10
      000449 25 36            [12] 1282 	add	a,_lettersToLeft
      00044B F5 82            [12] 1283 	mov	dpl,a
      00044D 12 07 09         [24] 1284 	lcall	_UART0_buf_write
                                   1285 ;	main.c:219: UART0_buf_write(lettersToLeft + LETTER_COUNT);
      000450 74 03            [12] 1286 	mov	a,#0x03
      000452 25 36            [12] 1287 	add	a,_lettersToLeft
      000454 F5 82            [12] 1288 	mov	dpl,a
      000456 12 07 09         [24] 1289 	lcall	_UART0_buf_write
                                   1290 ;	main.c:220: UART0_buf_write(brightness);
      000459 85 3B 82         [24] 1291 	mov	dpl,_brightness
      00045C 02 07 09         [24] 1292 	ljmp	_UART0_buf_write
                                   1293 ;------------------------------------------------------------
                                   1294 ;Allocation info for local variables in function 'main'
                                   1295 ;------------------------------------------------------------
                                   1296 ;c                         Allocated to registers 
                                   1297 ;frameCount                Allocated to registers r7 
                                   1298 ;------------------------------------------------------------
                                   1299 ;	main.c:224: void main() {
                                   1300 ;	-----------------------------------------
                                   1301 ;	 function main
                                   1302 ;	-----------------------------------------
      00045F                       1303 _main:
                                   1304 ;	main.c:227: uint8_t frameCount = 0; // TODO: replace me with timer
      00045F 7F 00            [12] 1305 	mov	r7,#0x00
                                   1306 ;	main.c:228: pattern = 0;
                                   1307 ;	1-genFromRTrack replaced	mov	_pattern,#0x00
      000461 8F 3C            [24] 1308 	mov	_pattern,r7
                                   1309 ;	main.c:230: initBoard();
      000463 C0 07            [24] 1310 	push	ar7
      000465 12 01 1B         [24] 1311 	lcall	_initBoard
                                   1312 ;	main.c:232: icn2053_begin();
      000468 12 06 10         [24] 1313 	lcall	_icn2053_begin
                                   1314 ;	main.c:234: UART0_buf_write('0');
      00046B 75 82 30         [24] 1315 	mov	dpl,#0x30
      00046E 12 07 09         [24] 1316 	lcall	_UART0_buf_write
                                   1317 ;	main.c:235: UART1_buf_write('1');
      000471 75 82 31         [24] 1318 	mov	dpl,#0x31
      000474 12 07 BF         [24] 1319 	lcall	_UART1_buf_write
      000477 D0 07            [24] 1320 	pop	ar7
                                   1321 ;	main.c:237: while (1) {
      000479                       1322 00115$:
                                   1323 ;	main.c:238: if(BUTTON1 == 0) {
      000479 20 B5 0A         [24] 1324 	jb	_BUTTON1,00104$
                                   1325 ;	main.c:239: pattern++;
      00047C 05 3C            [12] 1326 	inc	_pattern
                                   1327 ;	main.c:240: if(pattern == PATTERN_COUNT)
      00047E 74 02            [12] 1328 	mov	a,#0x02
      000480 B5 3C 03         [24] 1329 	cjne	a,_pattern,00104$
                                   1330 ;	main.c:241: pattern = 0;
      000483 75 3C 00         [24] 1331 	mov	_pattern,#0x00
      000486                       1332 00104$:
                                   1333 ;	main.c:245: if(BUTTON2 == 0) {
      000486 20 B3 0F         [24] 1334 	jb	_BUTTON2,00106$
                                   1335 ;	main.c:246: EA = 0;
      000489 C2 AF            [12] 1336 	clr	_EA
                                   1337 ;	main.c:247: bootloader();
      00048B C0 07            [24] 1338 	push	ar7
      00048D 85 23 82         [24] 1339 	mov	dpl,_bootloader
      000490 85 24 83         [24] 1340 	mov	dph,(_bootloader + 1)
      000493 12 00 59         [24] 1341 	lcall	__sdcc_call_dptr
      000496 D0 07            [24] 1342 	pop	ar7
      000498                       1343 00106$:
                                   1344 ;	main.c:261: if(pattern == 0)
      000498 E5 3C            [12] 1345 	mov	a,_pattern
      00049A 70 09            [24] 1346 	jnz	00110$
                                   1347 ;	main.c:262: fadeLetters();
      00049C C0 07            [24] 1348 	push	ar7
      00049E 12 02 ED         [24] 1349 	lcall	_fadeLetters
      0004A1 D0 07            [24] 1350 	pop	ar7
      0004A3 80 0C            [24] 1351 	sjmp	00111$
      0004A5                       1352 00110$:
                                   1353 ;	main.c:263: else if(pattern == 1)
      0004A5 74 01            [12] 1354 	mov	a,#0x01
      0004A7 B5 3C 07         [24] 1355 	cjne	a,_pattern,00111$
                                   1356 ;	main.c:264: fadeLeds();
      0004AA C0 07            [24] 1357 	push	ar7
      0004AC 12 01 65         [24] 1358 	lcall	_fadeLeds
      0004AF D0 07            [24] 1359 	pop	ar7
      0004B1                       1360 00111$:
                                   1361 ;	main.c:266: icn2053_updateDisplay(ledData, LED_COUNT);
      0004B1 75 0A 10         [24] 1362 	mov	_icn2053_updateDisplay_PARM_2,#0x10
      0004B4 90 00 25         [24] 1363 	mov	dptr,#_ledData
      0004B7 75 F0 40         [24] 1364 	mov	b,#0x40
      0004BA C0 07            [24] 1365 	push	ar7
      0004BC 12 06 1F         [24] 1366 	lcall	_icn2053_updateDisplay
      0004BF D0 07            [24] 1367 	pop	ar7
                                   1368 ;	main.c:268: frameCount++;
      0004C1 0F               [12] 1369 	inc	r7
                                   1370 ;	main.c:270: if(frameCount > 50) {
      0004C2 EF               [12] 1371 	mov	a,r7
      0004C3 24 CD            [12] 1372 	add	a,#0xff - 0x32
      0004C5 50 B2            [24] 1373 	jnc	00115$
                                   1374 ;	main.c:271: frameCount = 0;
      0004C7 7F 00            [12] 1375 	mov	r7,#0x00
      0004C9 80 AE            [24] 1376 	sjmp	00115$
                                   1377 	.area CSEG    (CODE)
                                   1378 	.area CONST   (CODE)
                                   1379 	.area XINIT   (CODE)
                                   1380 	.area CABS    (ABS,CODE)
