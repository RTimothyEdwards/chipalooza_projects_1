/*----------------------------------------------*/
/* Definitions for the chipalooza_testchip1	*/
/*----------------------------------------------*/
/* Written by Tim Edwards, Efabless		*/
/* November 22, 2024				*/
/*----------------------------------------------*/

/* Note that bit definitions for multiplexers have two
 * definitions for the same bit,  indicating the
 * selection of the two projects shared by the
 * multiplexer.
 *
 * Some definitions are multi-bit masks indicating
 * the range of bits used by the value.  This does
 * not indicate what order the bits are in, and for
 * many multi-bit values, the bits are scrambled.
 * See the chipalooza_utils.c set of utility
 * routines for a more comprehensive description of
 * the value bit fields.
 */

/* Logic analyzer data in bits */

/* Bits on logic analyzer word 0 */
#define BANDGAP_TRIM_MASK  0x0001fffe
#define SEL_SRC_TEST1	   0x00020000
#define SEL_BANDGAP_OUT	   0x00040000
#define NSEL_SRC_TEST0	   0x00040000
#define HSXO_ENABLE	   0x00080000
#define HSXO_STANDBY	   0x00100000
#define LPAMP_ENABLE	   0x00200000
#define SEL_COMP_INM	   0x00400000
#define NSEL_LPAMP_INP	   0x00400000
#define SEL_COMP_INP	   0x00800000
#define NSEL_LPAMP_INM	   0x00800000
#define COMP_TRIM_MASK_L   0x0e000000
#define COMP_ENABLE	   0x10000000
#define COMP_HYST_MASK	   0x60000000
#define COMP_TRIM_MASK_M   0x80000000   

/* Bits on logic analyzer word 1 */
#define COMP_TRIM_MASK_H   0x00000003
#define SEL_HGBWAMP_INP	   0x00000004
#define NSEL_TEMP_VBE1	   0x00000004
#define TEMP_ENABLE	   0x00000008
#define SEL_HGBWAMP_INM    0x00000010
#define NSEL_TEMP_VBE2	   0x00000010
#define HGBWAMP_ENABLE     0x00000020
#define NENA_SRC_TEST1	   0x00000040
#define NENA_LSXO_BIAS	   0x00000080
#define NENA_HGBWAMP_BIAS  0x00000100
#define NENA_POR_BIAS	   0x00000200
#define NENA_OV1_BIAS	   0x00000400
#define NENA_BRNOUT_BIAS   0x00000800
#define NENA_COMP_BIAS	   0x00001000
#define NENA_OV2_BIAS	   0x00002000
#define NENA_LPAMP_BIAS    0x00004000
#define NENA_HSXO_BIAS	   0x00008000
#define NENA_SOURCE_BIAS   0x00010000
#define NENA_SRC_TEST0	   0x00020000
#define NENA_BANDGAP_PWR   0x00040000
#define NENA_HSXO_PWR	   0x00100000
#define NENA_LPAMP_PWR	   0x00400000
#define NENA_COMP_PWR	   0x01000000
#define NENA_TEMP_PWR	   0x04000000
#define NENA_HGBWAMP_PWR   0x10000000
#define NENA_UNUSED1_PWR   0x40000000

/* Bits on logic analyzer word 2 */
#define NENA_OV2_PWR	   0x00000002
#define NENA_UNUSED2_PWR   0x00000008
#define NENA_LSXO_PWR	   0x00000020
#define NENA_UNUSED3_PWR   0x00000080
#define NENA_POR_PWR	   0x00000200
#define NENA_OV1_PWR	   0x00000800
#define NENA_BRNOUT_PWR	   0x00002000
#define ENA_SINK_TEST0	   0x00004000
#define ENA_BIASGEN	   0x00008000
#define ENA_SINK_UNUSED1   0x00010000
#define ENA_SINK_5000	   0x00020000
#define ENA_SINK_UNUSED2   0x00040000
#define ENA_SINK_3700	   0x00080000
#define ENA_SINK_TEST1	   0x00100000
#define LSXO_STANDBY	   0x00200000
#define LSXO_ENABLE	   0x00400000
#define OV2_TRIP_MASK	   0x07800000
#define OV2_ENABLE	   0x08000000
#define POR_RC_DISABLE	   0x10000000
#define POR_RC_ENABLE	   0x20000000
#define POR_FORCE_PDN	   0x40000000
#define POR_ISRC_SEL	   0x80000000

/* Bits on logic analyzer word 3 */
#define POR_TRIP_MASK	   0x00000007
#define POR_ONESHOT	   0x00000008
#define OV1_ENABLE	   0x00000010
#define OV1_ISRC_SEL	   0x00000020
#define OV1_TRIP_MASK	   0x000003c0
#define BRNOUT_VTRIP_MASK  0x00001c00
#define BRNOUT_ENABLE	   0x00002000
#define BRNOUT_ISRC_SEL	   0x00004000
#define BRNOUT_OTRIP_MASK  0x00038000
#define BRNOUT_RC_DISABLE  0x00040000
#define BRNOUT_RC_ENABLE   0x00080000
#define BRNOUT_ONESHOT	   0x00100000
#define BRNOUT_TIMEOUT	   0x00200000
#define SEL_SINK_TEST0	   0x00400000
#define POR_TIMEOUT	   0x00800000
#define POR_START_TIMEOUT  0x01000000
#define SEL_SINK_5000	   0x02000000
#define SEL_1P2_BIAS	   0x04000000
#define SEL_SINK_3700	   0x08000000
#define SEL_SINK_TEST1	   0x10000000
#define ENA_SINK_UNUSED3   0x20000000

/* Note that the three "TIMEOUT" bits are data inputs, not outputs */

