/*******************************************************************************
 * Copyright (C) 2024 MINRES Technologies GmbH
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 *******************************************************************************/

#ifndef _RV64GC_H_
#define _RV64GC_H_
// clang-format off
#include <array>
#include <iss/arch/traits.h>
#include <iss/arch_if.h>
#include <iss/vm_if.h>

namespace iss {
namespace arch {

struct rv64gc;

template <> struct traits<rv64gc> {

    constexpr static char const* const core_type = "RV64GC";
    
    static constexpr std::array<const char*, 69> reg_names{
        {"x0", "x1", "x2", "x3", "x4", "x5", "x6", "x7", "x8", "x9", "x10", "x11", "x12", "x13", "x14", "x15", "x16", "x17", "x18", "x19", "x20", "x21", "x22", "x23", "x24", "x25", "x26", "x27", "x28", "x29", "x30", "x31", "pc", "next_pc", "priv", "dpc", "f0", "f1", "f2", "f3", "f4", "f5", "f6", "f7", "f8", "f9", "f10", "f11", "f12", "f13", "f14", "f15", "f16", "f17", "f18", "f19", "f20", "f21", "f22", "f23", "f24", "f25", "f26", "f27", "f28", "f29", "f30", "f31", "fcsr"}};
 
    static constexpr std::array<const char*, 69> reg_aliases{
        {"zero", "ra", "sp", "gp", "tp", "t0", "t1", "t2", "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5", "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7", "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6", "pc", "next_pc", "priv", "dpc", "f0", "f1", "f2", "f3", "f4", "f5", "f6", "f7", "f8", "f9", "f10", "f11", "f12", "f13", "f14", "f15", "f16", "f17", "f18", "f19", "f20", "f21", "f22", "f23", "f24", "f25", "f26", "f27", "f28", "f29", "f30", "f31", "fcsr"}};

    enum constants {MISA_VAL=1073746221ULL, MARCHID_VAL=0ULL, CLIC_NUM_IRQ=0ULL, XLEN=64ULL, FLEN=64ULL, INSTR_ALIGNMENT=2ULL, RFS=32ULL, fence=0ULL, fencei=1ULL, fencevmal=2ULL, fencevmau=3ULL, RV_CSR_FFLAGS=1ULL, RV_CSR_FRM=2ULL, RV_CSR_FCSR=3ULL, RV_CSR_UTVT=7ULL, RV_CSR_VSTART=8ULL, RV_CSR_VXSAT=9ULL, RV_CSR_VXRM=10ULL, RV_CSR_VCSR=15ULL, RV_CSR_SEED=21ULL, RV_CSR_UNXTI=69ULL, RV_CSR_UINTSTATUS=70ULL, RV_CSR_USCRATCHCSW=72ULL, RV_CSR_USCRATCHCSWL=73ULL, RV_CSR_SSTATUS=256ULL, RV_CSR_SEDELEG=258ULL, RV_CSR_SIDELEG=259ULL, RV_CSR_SIE=260ULL, RV_CSR_STVEC=261ULL, RV_CSR_SCOUNTEREN=262ULL, RV_CSR_STVT=263ULL, RV_CSR_SENVCFG=266ULL, RV_CSR_SSTATEEN0=268ULL, RV_CSR_SSTATEEN1=269ULL, RV_CSR_SSTATEEN2=270ULL, RV_CSR_SSTATEEN3=271ULL, RV_CSR_SSCRATCH=320ULL, RV_CSR_SEPC=321ULL, RV_CSR_SCAUSE=322ULL, RV_CSR_STVAL=323ULL, RV_CSR_SIP=324ULL, RV_CSR_SNXTI=325ULL, RV_CSR_SINTSTATUS=326ULL, RV_CSR_SSCRATCHCSW=328ULL, RV_CSR_SSCRATCHCSWL=329ULL, RV_CSR_STIMECMP=333ULL, RV_CSR_STIMECMPH=349ULL, RV_CSR_SATP=384ULL, RV_CSR_VSSTATUS=512ULL, RV_CSR_VSIE=516ULL, RV_CSR_VSTVEC=517ULL, RV_CSR_VSSCRATCH=576ULL, RV_CSR_VSEPC=577ULL, RV_CSR_VSCAUSE=578ULL, RV_CSR_VSTVAL=579ULL, RV_CSR_VSIP=580ULL, RV_CSR_VSTIMECMP=589ULL, RV_CSR_VSTIMECMPH=605ULL, RV_CSR_VSATP=640ULL, RV_CSR_MSTATUS=768ULL, RV_CSR_MISA=769ULL, RV_CSR_MEDELEG=770ULL, RV_CSR_MIDELEG=771ULL, RV_CSR_MIE=772ULL, RV_CSR_MTVEC=773ULL, RV_CSR_MCOUNTEREN=774ULL, RV_CSR_MTVT=775ULL, RV_CSR_MENVCFG=778ULL, RV_CSR_MSTATEEN0=780ULL, RV_CSR_MSTATEEN1=781ULL, RV_CSR_MSTATEEN2=782ULL, RV_CSR_MSTATEEN3=783ULL, RV_CSR_MSTATUSH=784ULL, RV_CSR_MENVCFGH=794ULL, RV_CSR_MSTATEEN0H=796ULL, RV_CSR_MSTATEEN1H=797ULL, RV_CSR_MSTATEEN2H=798ULL, RV_CSR_MSTATEEN3H=799ULL, RV_CSR_MCOUNTINHIBIT=800ULL, RV_CSR_MHPMEVENT3=803ULL, RV_CSR_MHPMEVENT4=804ULL, RV_CSR_MHPMEVENT5=805ULL, RV_CSR_MHPMEVENT6=806ULL, RV_CSR_MHPMEVENT7=807ULL, RV_CSR_MHPMEVENT8=808ULL, RV_CSR_MHPMEVENT9=809ULL, RV_CSR_MHPMEVENT10=810ULL, RV_CSR_MHPMEVENT11=811ULL, RV_CSR_MHPMEVENT12=812ULL, RV_CSR_MHPMEVENT13=813ULL, RV_CSR_MHPMEVENT14=814ULL, RV_CSR_MHPMEVENT15=815ULL, RV_CSR_MHPMEVENT16=816ULL, RV_CSR_MHPMEVENT17=817ULL, RV_CSR_MHPMEVENT18=818ULL, RV_CSR_MHPMEVENT19=819ULL, RV_CSR_MHPMEVENT20=820ULL, RV_CSR_MHPMEVENT21=821ULL, RV_CSR_MHPMEVENT22=822ULL, RV_CSR_MHPMEVENT23=823ULL, RV_CSR_MHPMEVENT24=824ULL, RV_CSR_MHPMEVENT25=825ULL, RV_CSR_MHPMEVENT26=826ULL, RV_CSR_MHPMEVENT27=827ULL, RV_CSR_MHPMEVENT28=828ULL, RV_CSR_MHPMEVENT29=829ULL, RV_CSR_MHPMEVENT30=830ULL, RV_CSR_MHPMEVENT31=831ULL, RV_CSR_MSCRATCH=832ULL, RV_CSR_MEPC=833ULL, RV_CSR_MCAUSE=834ULL, RV_CSR_MTVAL=835ULL, RV_CSR_MIP=836ULL, RV_CSR_MNXTI=837ULL, RV_CSR_MINTSTATUS=838ULL, RV_CSR_MSCRATCHCSW=840ULL, RV_CSR_MSCRATCHCSWL=841ULL, RV_CSR_MTINST=842ULL, RV_CSR_MTVAL2=843ULL, RV_CSR_PMPCFG0=928ULL, RV_CSR_PMPCFG1=929ULL, RV_CSR_PMPCFG2=930ULL, RV_CSR_PMPCFG3=931ULL, RV_CSR_PMPCFG4=932ULL, RV_CSR_PMPCFG5=933ULL, RV_CSR_PMPCFG6=934ULL, RV_CSR_PMPCFG7=935ULL, RV_CSR_PMPCFG8=936ULL, RV_CSR_PMPCFG9=937ULL, RV_CSR_PMPCFG10=938ULL, RV_CSR_PMPCFG11=939ULL, RV_CSR_PMPCFG12=940ULL, RV_CSR_PMPCFG13=941ULL, RV_CSR_PMPCFG14=942ULL, RV_CSR_PMPCFG15=943ULL, RV_CSR_PMPADDR0=944ULL, RV_CSR_PMPADDR1=945ULL, RV_CSR_PMPADDR2=946ULL, RV_CSR_PMPADDR3=947ULL, RV_CSR_PMPADDR4=948ULL, RV_CSR_PMPADDR5=949ULL, RV_CSR_PMPADDR6=950ULL, RV_CSR_PMPADDR7=951ULL, RV_CSR_PMPADDR8=952ULL, RV_CSR_PMPADDR9=953ULL, RV_CSR_PMPADDR10=954ULL, RV_CSR_PMPADDR11=955ULL, RV_CSR_PMPADDR12=956ULL, RV_CSR_PMPADDR13=957ULL, RV_CSR_PMPADDR14=958ULL, RV_CSR_PMPADDR15=959ULL, RV_CSR_PMPADDR16=960ULL, RV_CSR_PMPADDR17=961ULL, RV_CSR_PMPADDR18=962ULL, RV_CSR_PMPADDR19=963ULL, RV_CSR_PMPADDR20=964ULL, RV_CSR_PMPADDR21=965ULL, RV_CSR_PMPADDR22=966ULL, RV_CSR_PMPADDR23=967ULL, RV_CSR_PMPADDR24=968ULL, RV_CSR_PMPADDR25=969ULL, RV_CSR_PMPADDR26=970ULL, RV_CSR_PMPADDR27=971ULL, RV_CSR_PMPADDR28=972ULL, RV_CSR_PMPADDR29=973ULL, RV_CSR_PMPADDR30=974ULL, RV_CSR_PMPADDR31=975ULL, RV_CSR_PMPADDR32=976ULL, RV_CSR_PMPADDR33=977ULL, RV_CSR_PMPADDR34=978ULL, RV_CSR_PMPADDR35=979ULL, RV_CSR_PMPADDR36=980ULL, RV_CSR_PMPADDR37=981ULL, RV_CSR_PMPADDR38=982ULL, RV_CSR_PMPADDR39=983ULL, RV_CSR_PMPADDR40=984ULL, RV_CSR_PMPADDR41=985ULL, RV_CSR_PMPADDR42=986ULL, RV_CSR_PMPADDR43=987ULL, RV_CSR_PMPADDR44=988ULL, RV_CSR_PMPADDR45=989ULL, RV_CSR_PMPADDR46=990ULL, RV_CSR_PMPADDR47=991ULL, RV_CSR_PMPADDR48=992ULL, RV_CSR_PMPADDR49=993ULL, RV_CSR_PMPADDR50=994ULL, RV_CSR_PMPADDR51=995ULL, RV_CSR_PMPADDR52=996ULL, RV_CSR_PMPADDR53=997ULL, RV_CSR_PMPADDR54=998ULL, RV_CSR_PMPADDR55=999ULL, RV_CSR_PMPADDR56=1000ULL, RV_CSR_PMPADDR57=1001ULL, RV_CSR_PMPADDR58=1002ULL, RV_CSR_PMPADDR59=1003ULL, RV_CSR_PMPADDR60=1004ULL, RV_CSR_PMPADDR61=1005ULL, RV_CSR_PMPADDR62=1006ULL, RV_CSR_PMPADDR63=1007ULL, RV_CSR_SCONTEXT=1448ULL, RV_CSR_HSTATUS=1536ULL, RV_CSR_HEDELEG=1538ULL, RV_CSR_HIDELEG=1539ULL, RV_CSR_HIE=1540ULL, RV_CSR_HTIMEDELTA=1541ULL, RV_CSR_HCOUNTEREN=1542ULL, RV_CSR_HGEIE=1543ULL, RV_CSR_HENVCFG=1546ULL, RV_CSR_HSTATEEN0=1548ULL, RV_CSR_HSTATEEN1=1549ULL, RV_CSR_HSTATEEN2=1550ULL, RV_CSR_HSTATEEN3=1551ULL, RV_CSR_HTIMEDELTAH=1557ULL, RV_CSR_HENVCFGH=1562ULL, RV_CSR_HSTATEEN0H=1564ULL, RV_CSR_HSTATEEN1H=1565ULL, RV_CSR_HSTATEEN2H=1566ULL, RV_CSR_HSTATEEN3H=1567ULL, RV_CSR_HTVAL=1603ULL, RV_CSR_HIP=1604ULL, RV_CSR_HVIP=1605ULL, RV_CSR_HTINST=1610ULL, RV_CSR_HGATP=1664ULL, RV_CSR_HCONTEXT=1704ULL, RV_CSR_MHPMEVENT3H=1827ULL, RV_CSR_MHPMEVENT4H=1828ULL, RV_CSR_MHPMEVENT5H=1829ULL, RV_CSR_MHPMEVENT6H=1830ULL, RV_CSR_MHPMEVENT7H=1831ULL, RV_CSR_MHPMEVENT8H=1832ULL, RV_CSR_MHPMEVENT9H=1833ULL, RV_CSR_MHPMEVENT10H=1834ULL, RV_CSR_MHPMEVENT11H=1835ULL, RV_CSR_MHPMEVENT12H=1836ULL, RV_CSR_MHPMEVENT13H=1837ULL, RV_CSR_MHPMEVENT14H=1838ULL, RV_CSR_MHPMEVENT15H=1839ULL, RV_CSR_MHPMEVENT16H=1840ULL, RV_CSR_MHPMEVENT17H=1841ULL, RV_CSR_MHPMEVENT18H=1842ULL, RV_CSR_MHPMEVENT19H=1843ULL, RV_CSR_MHPMEVENT20H=1844ULL, RV_CSR_MHPMEVENT21H=1845ULL, RV_CSR_MHPMEVENT22H=1846ULL, RV_CSR_MHPMEVENT23H=1847ULL, RV_CSR_MHPMEVENT24H=1848ULL, RV_CSR_MHPMEVENT25H=1849ULL, RV_CSR_MHPMEVENT26H=1850ULL, RV_CSR_MHPMEVENT27H=1851ULL, RV_CSR_MHPMEVENT28H=1852ULL, RV_CSR_MHPMEVENT29H=1853ULL, RV_CSR_MHPMEVENT30H=1854ULL, RV_CSR_MHPMEVENT31H=1855ULL, RV_CSR_MSECCFG=1863ULL, RV_CSR_MSECCFGH=1879ULL, RV_CSR_TSELECT=1952ULL, RV_CSR_TDATA1=1953ULL, RV_CSR_TDATA2=1954ULL, RV_CSR_TDATA3=1955ULL, RV_CSR_TINFO=1956ULL, RV_CSR_TCONTROL=1957ULL, RV_CSR_MCONTEXT=1960ULL, RV_CSR_MSCONTEXT=1962ULL, RV_CSR_DCSR=1968ULL, RV_CSR_DPC=1969ULL, RV_CSR_DSCRATCH0=1970ULL, RV_CSR_DSCRATCH1=1971ULL, RV_CSR_MCYCLE=2816ULL, RV_CSR_MINSTRET=2818ULL, RV_CSR_MHPMCOUNTER3=2819ULL, RV_CSR_MHPMCOUNTER4=2820ULL, RV_CSR_MHPMCOUNTER5=2821ULL, RV_CSR_MHPMCOUNTER6=2822ULL, RV_CSR_MHPMCOUNTER7=2823ULL, RV_CSR_MHPMCOUNTER8=2824ULL, RV_CSR_MHPMCOUNTER9=2825ULL, RV_CSR_MHPMCOUNTER10=2826ULL, RV_CSR_MHPMCOUNTER11=2827ULL, RV_CSR_MHPMCOUNTER12=2828ULL, RV_CSR_MHPMCOUNTER13=2829ULL, RV_CSR_MHPMCOUNTER14=2830ULL, RV_CSR_MHPMCOUNTER15=2831ULL, RV_CSR_MHPMCOUNTER16=2832ULL, RV_CSR_MHPMCOUNTER17=2833ULL, RV_CSR_MHPMCOUNTER18=2834ULL, RV_CSR_MHPMCOUNTER19=2835ULL, RV_CSR_MHPMCOUNTER20=2836ULL, RV_CSR_MHPMCOUNTER21=2837ULL, RV_CSR_MHPMCOUNTER22=2838ULL, RV_CSR_MHPMCOUNTER23=2839ULL, RV_CSR_MHPMCOUNTER24=2840ULL, RV_CSR_MHPMCOUNTER25=2841ULL, RV_CSR_MHPMCOUNTER26=2842ULL, RV_CSR_MHPMCOUNTER27=2843ULL, RV_CSR_MHPMCOUNTER28=2844ULL, RV_CSR_MHPMCOUNTER29=2845ULL, RV_CSR_MHPMCOUNTER30=2846ULL, RV_CSR_MHPMCOUNTER31=2847ULL, RV_CSR_MCYCLEH=2944ULL, RV_CSR_MINSTRETH=2946ULL, RV_CSR_MHPMCOUNTER3H=2947ULL, RV_CSR_MHPMCOUNTER4H=2948ULL, RV_CSR_MHPMCOUNTER5H=2949ULL, RV_CSR_MHPMCOUNTER6H=2950ULL, RV_CSR_MHPMCOUNTER7H=2951ULL, RV_CSR_MHPMCOUNTER8H=2952ULL, RV_CSR_MHPMCOUNTER9H=2953ULL, RV_CSR_MHPMCOUNTER10H=2954ULL, RV_CSR_MHPMCOUNTER11H=2955ULL, RV_CSR_MHPMCOUNTER12H=2956ULL, RV_CSR_MHPMCOUNTER13H=2957ULL, RV_CSR_MHPMCOUNTER14H=2958ULL, RV_CSR_MHPMCOUNTER15H=2959ULL, RV_CSR_MHPMCOUNTER16H=2960ULL, RV_CSR_MHPMCOUNTER17H=2961ULL, RV_CSR_MHPMCOUNTER18H=2962ULL, RV_CSR_MHPMCOUNTER19H=2963ULL, RV_CSR_MHPMCOUNTER20H=2964ULL, RV_CSR_MHPMCOUNTER21H=2965ULL, RV_CSR_MHPMCOUNTER22H=2966ULL, RV_CSR_MHPMCOUNTER23H=2967ULL, RV_CSR_MHPMCOUNTER24H=2968ULL, RV_CSR_MHPMCOUNTER25H=2969ULL, RV_CSR_MHPMCOUNTER26H=2970ULL, RV_CSR_MHPMCOUNTER27H=2971ULL, RV_CSR_MHPMCOUNTER28H=2972ULL, RV_CSR_MHPMCOUNTER29H=2973ULL, RV_CSR_MHPMCOUNTER30H=2974ULL, RV_CSR_MHPMCOUNTER31H=2975ULL, RV_CSR_CYCLE=3072ULL, RV_CSR_TIME=3073ULL, RV_CSR_INSTRET=3074ULL, RV_CSR_HPMCOUNTER3=3075ULL, RV_CSR_HPMCOUNTER4=3076ULL, RV_CSR_HPMCOUNTER5=3077ULL, RV_CSR_HPMCOUNTER6=3078ULL, RV_CSR_HPMCOUNTER7=3079ULL, RV_CSR_HPMCOUNTER8=3080ULL, RV_CSR_HPMCOUNTER9=3081ULL, RV_CSR_HPMCOUNTER10=3082ULL, RV_CSR_HPMCOUNTER11=3083ULL, RV_CSR_HPMCOUNTER12=3084ULL, RV_CSR_HPMCOUNTER13=3085ULL, RV_CSR_HPMCOUNTER14=3086ULL, RV_CSR_HPMCOUNTER15=3087ULL, RV_CSR_HPMCOUNTER16=3088ULL, RV_CSR_HPMCOUNTER17=3089ULL, RV_CSR_HPMCOUNTER18=3090ULL, RV_CSR_HPMCOUNTER19=3091ULL, RV_CSR_HPMCOUNTER20=3092ULL, RV_CSR_HPMCOUNTER21=3093ULL, RV_CSR_HPMCOUNTER22=3094ULL, RV_CSR_HPMCOUNTER23=3095ULL, RV_CSR_HPMCOUNTER24=3096ULL, RV_CSR_HPMCOUNTER25=3097ULL, RV_CSR_HPMCOUNTER26=3098ULL, RV_CSR_HPMCOUNTER27=3099ULL, RV_CSR_HPMCOUNTER28=3100ULL, RV_CSR_HPMCOUNTER29=3101ULL, RV_CSR_HPMCOUNTER30=3102ULL, RV_CSR_HPMCOUNTER31=3103ULL, RV_CSR_VL=3104ULL, RV_CSR_VTYPE=3105ULL, RV_CSR_VLENB=3106ULL, RV_CSR_CYCLEH=3200ULL, RV_CSR_TIMEH=3201ULL, RV_CSR_INSTRETH=3202ULL, RV_CSR_HPMCOUNTER3H=3203ULL, RV_CSR_HPMCOUNTER4H=3204ULL, RV_CSR_HPMCOUNTER5H=3205ULL, RV_CSR_HPMCOUNTER6H=3206ULL, RV_CSR_HPMCOUNTER7H=3207ULL, RV_CSR_HPMCOUNTER8H=3208ULL, RV_CSR_HPMCOUNTER9H=3209ULL, RV_CSR_HPMCOUNTER10H=3210ULL, RV_CSR_HPMCOUNTER11H=3211ULL, RV_CSR_HPMCOUNTER12H=3212ULL, RV_CSR_HPMCOUNTER13H=3213ULL, RV_CSR_HPMCOUNTER14H=3214ULL, RV_CSR_HPMCOUNTER15H=3215ULL, RV_CSR_HPMCOUNTER16H=3216ULL, RV_CSR_HPMCOUNTER17H=3217ULL, RV_CSR_HPMCOUNTER18H=3218ULL, RV_CSR_HPMCOUNTER19H=3219ULL, RV_CSR_HPMCOUNTER20H=3220ULL, RV_CSR_HPMCOUNTER21H=3221ULL, RV_CSR_HPMCOUNTER22H=3222ULL, RV_CSR_HPMCOUNTER23H=3223ULL, RV_CSR_HPMCOUNTER24H=3224ULL, RV_CSR_HPMCOUNTER25H=3225ULL, RV_CSR_HPMCOUNTER26H=3226ULL, RV_CSR_HPMCOUNTER27H=3227ULL, RV_CSR_HPMCOUNTER28H=3228ULL, RV_CSR_HPMCOUNTER29H=3229ULL, RV_CSR_HPMCOUNTER30H=3230ULL, RV_CSR_HPMCOUNTER31H=3231ULL, RV_CSR_SCOUNTOVF=3488ULL, RV_CSR_HGEIP=3602ULL, RV_CSR_MVENDORID=3857ULL, RV_CSR_MARCHID=3858ULL, RV_CSR_MIMPID=3859ULL, RV_CSR_MHARTID=3860ULL, RV_CSR_MCONFIGPTR=3861ULL, RV_CAUSE_MISALIGNED_FETCH=0ULL, RV_CAUSE_FETCH_ACCESS=1ULL, RV_CAUSE_ILLEGAL_INSTRUCTION=2ULL, RV_CAUSE_BREAKPOINT=3ULL, RV_CAUSE_MISALIGNED_LOAD=4ULL, RV_CAUSE_LOAD_ACCESS=5ULL, RV_CAUSE_MISALIGNED_STORE=6ULL, RV_CAUSE_STORE_ACCESS=7ULL, RV_CAUSE_USER_ECALL=8ULL, RV_CAUSE_SUPERVISOR_ECALL=9ULL, RV_CAUSE_VIRTUAL_SUPERVISOR_ECALL=10ULL, RV_CAUSE_MACHINE_ECALL=11ULL, RV_CAUSE_FETCH_PAGE_FAULT=12ULL, RV_CAUSE_LOAD_PAGE_FAULT=13ULL, RV_CAUSE_STORE_PAGE_FAULT=15ULL, RV_CAUSE_FETCH_GUEST_PAGE_FAULT=20ULL, RV_CAUSE_LOAD_GUEST_PAGE_FAULT=21ULL, RV_CAUSE_VIRTUAL_INSTRUCTION=22ULL, RV_CAUSE_STORE_GUEST_PAGE_FAULT=23ULL, RV_MSTATUS_UIE=1ULL, RV_MSTATUS_SIE=2ULL, RV_MSTATUS_HIE=4ULL, RV_MSTATUS_MIE=8ULL, RV_MSTATUS_UPIE=16ULL, RV_MSTATUS_SPIE=32ULL, RV_MSTATUS_UBE=64ULL, RV_MSTATUS_MPIE=128ULL, RV_MSTATUS_SPP=256ULL, RV_MSTATUS_VS=1536ULL, RV_MSTATUS_MPP=6144ULL, RV_MSTATUS_FS=24576ULL, RV_MSTATUS_XS=98304ULL, RV_MSTATUS_MPRV=131072ULL, RV_MSTATUS_SUM=262144ULL, RV_MSTATUS_MXR=524288ULL, RV_MSTATUS_TVM=1048576ULL, RV_MSTATUS_TW=2097152ULL, RV_MSTATUS_TSR=4194304ULL, RV_MSTATUS32_SD=1ULL, RV_PRV_U=0ULL, RV_PRV_S=1ULL, RV_PRV_H=2ULL, RV_PRV_M=3ULL, RV_IRQ_U_SOFT=0ULL, RV_IRQ_S_SOFT=1ULL, RV_IRQ_VS_SOFT=2ULL, RV_IRQ_M_SOFT=3ULL, RV_IRQ_U_TIMER=4ULL, RV_IRQ_S_TIMER=5ULL, RV_IRQ_VS_TIMER=6ULL, RV_IRQ_M_TIMER=7ULL, RV_IRQ_U_EXT=8ULL, RV_IRQ_S_EXT=9ULL, RV_IRQ_VS_EXT=10ULL, RV_IRQ_M_EXT=11ULL, RV_IRQ_S_GEXT=12ULL, RV_IRQ_COP=12ULL, RV_IRQ_LCOF=13ULL, RV_MIP_USIP=1ULL, RV_MIP_SSIP=1ULL, RV_MIP_VSSIP=1ULL, RV_MIP_MSIP=1ULL, RV_MIP_UTIP=1ULL, RV_MIP_STIP=1ULL, RV_MIP_VSTIP=1ULL, RV_MIP_MTIP=1ULL, RV_MIP_UEIP=1ULL, RV_MIP_SEIP=1ULL, RV_MIP_VSEIP=1ULL, RV_MIP_MEIP=1ULL, RV_MIP_SGEIP=1ULL, RV_MIP_LCOFIP=1ULL, CSR_SIZE=4096ULL, MUL_LEN=128ULL, FFLAG_MASK=31ULL};

    constexpr static unsigned FP_REGS_SIZE = 64;

    enum reg_e {
        X0, X1, X2, X3, X4, X5, X6, X7, X8, X9, X10, X11, X12, X13, X14, X15, X16, X17, X18, X19, X20, X21, X22, X23, X24, X25, X26, X27, X28, X29, X30, X31, PC, NEXT_PC, PRIV, DPC, F0, F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12, F13, F14, F15, F16, F17, F18, F19, F20, F21, F22, F23, F24, F25, F26, F27, F28, F29, F30, F31, FCSR, NUM_REGS, TRAP_STATE=NUM_REGS, PENDING_TRAP, ICOUNT, CYCLE, INSTRET, INSTRUCTION, LAST_BRANCH
    };

    using reg_t = uint64_t;

    using addr_t = uint64_t;

    using code_word_t = uint64_t; //TODO: check removal

    using virt_addr_t = iss::typed_addr_t<iss::address_type::VIRTUAL>;

    using phys_addr_t = iss::typed_addr_t<iss::address_type::PHYSICAL>;

    static constexpr std::array<const uint32_t, 76> reg_bit_widths{
        {64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,8,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,32,32,64,64,64,32,32}};

    static constexpr std::array<const uint32_t, 76> reg_byte_offsets{
        {0,8,16,24,32,40,48,56,64,72,80,88,96,104,112,120,128,136,144,152,160,168,176,184,192,200,208,216,224,232,240,248,256,264,272,273,281,289,297,305,313,321,329,337,345,353,361,369,377,385,393,401,409,417,425,433,441,449,457,465,473,481,489,497,505,513,521,529,537,545,549,553,561,569,577,581}};

    static const uint64_t addr_mask = (reg_t(1) << (XLEN - 1)) | ((reg_t(1) << (XLEN - 1)) - 1);

    enum sreg_flag_e { FLAGS };

    enum mem_type_e { MEM, FENCE, RES, CSR, IMEM = MEM };
    
    enum class opcode_e {
        LUI = 0,
        AUIPC = 1,
        JAL = 2,
        JALR = 3,
        BEQ = 4,
        BNE = 5,
        BLT = 6,
        BGE = 7,
        BLTU = 8,
        BGEU = 9,
        LB = 10,
        LH = 11,
        LW = 12,
        LBU = 13,
        LHU = 14,
        SB = 15,
        SH = 16,
        SW = 17,
        ADDI = 18,
        SLTI = 19,
        SLTIU = 20,
        XORI = 21,
        ORI = 22,
        ANDI = 23,
        SLLI = 24,
        SRLI = 25,
        SRAI = 26,
        ADD = 27,
        SUB = 28,
        SLL = 29,
        SLT = 30,
        SLTU = 31,
        XOR = 32,
        SRL = 33,
        SRA = 34,
        OR = 35,
        AND = 36,
        FENCE = 37,
        ECALL = 38,
        EBREAK = 39,
        MRET = 40,
        WFI = 41,
        LWU = 42,
        LD = 43,
        SD = 44,
        ADDIW = 45,
        SLLIW = 46,
        SRLIW = 47,
        SRAIW = 48,
        ADDW = 49,
        SUBW = 50,
        SLLW = 51,
        SRLW = 52,
        SRAW = 53,
        CSRRW = 54,
        CSRRS = 55,
        CSRRC = 56,
        CSRRWI = 57,
        CSRRSI = 58,
        CSRRCI = 59,
        FENCE_I = 60,
        MUL = 61,
        MULH = 62,
        MULHSU = 63,
        MULHU = 64,
        DIV = 65,
        DIVU = 66,
        REM = 67,
        REMU = 68,
        MULW = 69,
        DIVW = 70,
        DIVUW = 71,
        REMW = 72,
        REMUW = 73,
        LRW = 74,
        SCW = 75,
        AMOSWAPW = 76,
        AMOADDW = 77,
        AMOXORW = 78,
        AMOANDW = 79,
        AMOORW = 80,
        AMOMINW = 81,
        AMOMAXW = 82,
        AMOMINUW = 83,
        AMOMAXUW = 84,
        LRD = 85,
        SCD = 86,
        AMOSWAPD = 87,
        AMOADDD = 88,
        AMOXORD = 89,
        AMOANDD = 90,
        AMOORD = 91,
        AMOMIND = 92,
        AMOMAXD = 93,
        AMOMINUD = 94,
        AMOMAXUD = 95,
        C__ADDI4SPN = 96,
        C__LW = 97,
        C__LD = 98,
        C__SW = 99,
        C__SD = 100,
        C__ADDI = 101,
        C__NOP = 102,
        C__ADDIW = 103,
        C__LI = 104,
        C__LUI = 105,
        C__ADDI16SP = 106,
        __reserved_clui = 107,
        C__SRLI = 108,
        C__SRAI = 109,
        C__ANDI = 110,
        C__SUB = 111,
        C__XOR = 112,
        C__OR = 113,
        C__AND = 114,
        C__SUBW = 115,
        C__ADDW = 116,
        C__J = 117,
        C__BEQZ = 118,
        C__BNEZ = 119,
        C__SLLI = 120,
        C__LWSP = 121,
        C__LDSP = 122,
        C__MV = 123,
        C__JR = 124,
        __reserved_cmv = 125,
        C__ADD = 126,
        C__JALR = 127,
        C__EBREAK = 128,
        C__SWSP = 129,
        C__SDSP = 130,
        DII = 131,
        FLW = 132,
        FSW = 133,
        FMADD__S = 134,
        FMSUB__S = 135,
        FNMADD__S = 136,
        FNMSUB__S = 137,
        FADD__S = 138,
        FSUB__S = 139,
        FMUL__S = 140,
        FDIV__S = 141,
        FSQRT__S = 142,
        FSGNJ__S = 143,
        FSGNJN__S = 144,
        FSGNJX__S = 145,
        FMIN__S = 146,
        FMAX__S = 147,
        FCVT__W__S = 148,
        FCVT__WU__S = 149,
        FEQ__S = 150,
        FLT__S = 151,
        FLE__S = 152,
        FCLASS__S = 153,
        FCVT__S__W = 154,
        FCVT__S__WU = 155,
        FMV__X__W = 156,
        FMV__W__X = 157,
        FCVT_L_S = 158,
        FCVT_LU_S = 159,
        FCVT_S_L = 160,
        FCVT_S_LU = 161,
        FLD = 162,
        FSD = 163,
        FMADD_D = 164,
        FMSUB_D = 165,
        FNMADD_D = 166,
        FNMSUB_D = 167,
        FADD_D = 168,
        FSUB_D = 169,
        FMUL_D = 170,
        FDIV_D = 171,
        FSQRT_D = 172,
        FSGNJ_D = 173,
        FSGNJN_D = 174,
        FSGNJX_D = 175,
        FMIN_D = 176,
        FMAX_D = 177,
        FCVT_S_D = 178,
        FCVT_D_S = 179,
        FEQ_D = 180,
        FLT_D = 181,
        FLE_D = 182,
        FCLASS_D = 183,
        FCVT_W_D = 184,
        FCVT_WU_D = 185,
        FCVT_D_W = 186,
        FCVT_D_WU = 187,
        FCVT_L_D = 188,
        FCVT_LU_D = 189,
        FCVT_D_L = 190,
        FCVT_D_LU = 191,
        FMV_X_D = 192,
        FMV_D_X = 193,
        C__FLD = 194,
        C__FSD = 195,
        C__FLDSP = 196,
        C__FSDSP = 197,
        MAX_OPCODE
    };
};

struct rv64gc: public arch_if {

    using virt_addr_t = typename traits<rv64gc>::virt_addr_t;
    using phys_addr_t = typename traits<rv64gc>::phys_addr_t;
    using reg_t =  typename traits<rv64gc>::reg_t;
    using addr_t = typename traits<rv64gc>::addr_t;

    rv64gc();
    ~rv64gc();

    void reset(uint64_t address=0) override;

    uint8_t* get_regs_base_ptr() override;

    inline uint64_t get_icount() { return reg.icount; }

    inline bool should_stop() { return interrupt_sim; }

    inline uint64_t stop_code() { return interrupt_sim; }

    virtual phys_addr_t virt2phys(const iss::addr_t& addr);

    virtual iss::sync_type needed_sync() const { return iss::NO_SYNC; }

    inline uint32_t get_last_branch() { return reg.last_branch; }


#pragma pack(push, 1)
    struct RV64GC_regs { 
        uint64_t X0 = 0; 
        uint64_t X1 = 0; 
        uint64_t X2 = 0; 
        uint64_t X3 = 0; 
        uint64_t X4 = 0; 
        uint64_t X5 = 0; 
        uint64_t X6 = 0; 
        uint64_t X7 = 0; 
        uint64_t X8 = 0; 
        uint64_t X9 = 0; 
        uint64_t X10 = 0; 
        uint64_t X11 = 0; 
        uint64_t X12 = 0; 
        uint64_t X13 = 0; 
        uint64_t X14 = 0; 
        uint64_t X15 = 0; 
        uint64_t X16 = 0; 
        uint64_t X17 = 0; 
        uint64_t X18 = 0; 
        uint64_t X19 = 0; 
        uint64_t X20 = 0; 
        uint64_t X21 = 0; 
        uint64_t X22 = 0; 
        uint64_t X23 = 0; 
        uint64_t X24 = 0; 
        uint64_t X25 = 0; 
        uint64_t X26 = 0; 
        uint64_t X27 = 0; 
        uint64_t X28 = 0; 
        uint64_t X29 = 0; 
        uint64_t X30 = 0; 
        uint64_t X31 = 0; 
        uint64_t PC = 0; 
        uint64_t NEXT_PC = 0; 
        uint8_t PRIV = 0; 
        uint64_t DPC = 0; 
        uint64_t F0 = 0; 
        uint64_t F1 = 0; 
        uint64_t F2 = 0; 
        uint64_t F3 = 0; 
        uint64_t F4 = 0; 
        uint64_t F5 = 0; 
        uint64_t F6 = 0; 
        uint64_t F7 = 0; 
        uint64_t F8 = 0; 
        uint64_t F9 = 0; 
        uint64_t F10 = 0; 
        uint64_t F11 = 0; 
        uint64_t F12 = 0; 
        uint64_t F13 = 0; 
        uint64_t F14 = 0; 
        uint64_t F15 = 0; 
        uint64_t F16 = 0; 
        uint64_t F17 = 0; 
        uint64_t F18 = 0; 
        uint64_t F19 = 0; 
        uint64_t F20 = 0; 
        uint64_t F21 = 0; 
        uint64_t F22 = 0; 
        uint64_t F23 = 0; 
        uint64_t F24 = 0; 
        uint64_t F25 = 0; 
        uint64_t F26 = 0; 
        uint64_t F27 = 0; 
        uint64_t F28 = 0; 
        uint64_t F29 = 0; 
        uint64_t F30 = 0; 
        uint64_t F31 = 0; 
        uint64_t FCSR = 0;
        uint32_t trap_state = 0, pending_trap = 0;
        uint64_t icount = 0;
        uint64_t cycle = 0;
        uint64_t instret = 0;
        uint32_t instruction = 0;
        uint32_t last_branch = 0;
    } reg;
#pragma pack(pop)
    std::array<address_type, 4> addr_mode;
    
    uint64_t interrupt_sim=0;

    uint64_t get_fcsr(){return reg.FCSR;}
    void set_fcsr(uint64_t val){reg.FCSR = val;}      

};

}
}            
#endif /* _RV64GC_H_ */
// clang-format on
