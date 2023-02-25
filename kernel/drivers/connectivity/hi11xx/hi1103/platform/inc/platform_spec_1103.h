

#ifndef __PLATFORM_SPEC_1103_H__
#define __PLATFORM_SPEC_1103_H__

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#if ((_PRE_PRODUCT_ID == _PRE_PRODUCT_ID_HI1103_DEV) || (_PRE_PRODUCT_ID == _PRE_PRODUCT_ID_HI1103_HOST))

/*****************************************************************************
  1 ����ͷ�ļ�����
*****************************************************************************/
#include "oal_types.h"

/*****************************************************************************
  2 �궨��
*/
/*****************************************************************************
  1.1.1 �汾spec
*****************************************************************************/
/* оƬ�汾��1103��ɾ�� */
#if (_PRE_WLAN_CHIP_ASIC == _PRE_WLAN_CHIP_VERSION)
/* hi1151V100H */
#define WLAN_CHIP_VERSION_HI1151V100H           0x11510101
#else
/* hi1151V100H */
#define WLAN_CHIP_VERSION_HI1151V100H           0x11510100
#endif
/* hi1151V100L */
#define WLAN_CHIP_VERSION_HI1151V100L           0x11510102

/*�������Host��Device�ж���Ԥ���룬�޶�����mac_xxx�ĺ��������С��������ṹ�����ĺ�ɾ��*/
#define IS_HOST (_PRE_PRODUCT_ID == _PRE_PRODUCT_ID_HI1103_HOST)
#define IS_DEVICE (_PRE_PRODUCT_ID == _PRE_PRODUCT_ID_HI1103_DEV)

/*****************************************************************************
  1.1.2 ��Core��Ӧspec
*****************************************************************************/
#if (_PRE_OS_VERSION_RAW == _PRE_OS_VERSION)||(_PRE_OS_VERSION_WIN32_RAW == _PRE_OS_VERSION)
    /* WiFi��Ӧ��ϵͳCORE������ Ϊ1*/
    #define WLAN_FRW_MAX_NUM_CORES          1
#else
    /* WiFi��ӦLinuxϵͳCORE������ Ϊ1*/
    #define WLAN_FRW_MAX_NUM_CORES          1
#endif


/*****************************************************************************
  2 WLAN �궨��
*****************************************************************************/
/*****************************************************************************
  2.1 WLANоƬ��Ӧ��spec
*****************************************************************************/
#define WLAN_CHIP_MAX_NUM_PER_BOARD         1                       /* ÿ��board֧��chip�����������������ᳬ��8�� */

/* ��̬dbdc�Ͷ�̬dbdc hal device������Ϊ2 */
#ifdef _PRE_WLAN_FEATURE_DBDC
#define WLAN_DEVICE_MAX_NUM_PER_CHIP            2                     /* ÿ��chip֧��hal device�����������������ᳬ��8��,03Ӧ��Ϊ2,ĿǰӲ����֧�� */
#else
#define WLAN_DEVICE_MAX_NUM_PER_CHIP            1                     /* ÿ��chip֧��hal device�����������������ᳬ��8��,03Ӧ��Ϊ2,ĿǰӲ����֧�� */
#endif

#define WLAN_SERVICE_DEVICE_MAX_NUM_PER_CHIP    1                     /* ÿ��chip֧��ҵ��device�������� */

/* ����BOARD֧�ֵ�����hal device��Ŀ */
#define WLAN_DEVICE_SUPPORT_MAX_NUM_SPEC    (WLAN_CHIP_MAX_NUM_PER_BOARD * WLAN_DEVICE_MAX_NUM_PER_CHIP)

/* ����BOARD֧�ֵ�����ҵ��device��Ŀ */
#define WLAN_SERVICE_DEVICE_SUPPORT_MAX_NUM_SPEC    (WLAN_CHIP_MAX_NUM_PER_BOARD * WLAN_SERVICE_DEVICE_MAX_NUM_PER_CHIP)


#define WLAN_SERVICE_AP_MAX_NUM_PER_DEVICE      2   /* ҵ��AP�Ĺ�񣬽�֮ǰ��WLAN_SERVICE_VAP_MAX_NUM_PER_DEVICE�޸�*/
#define WLAN_SERVICE_STA_MAX_NUM_PER_DEVICE     3   /* ҵ��STA�Ĺ�� */
#define WLAN_AP_STA_COEXIST_VAP_NUM             0   /* ҵ��ap sta����ʱvap��Ŀ,Hi1103������STA+AP�������� */


/* �������ҵ��VAP������Ҫ�����豸ͬʱ������������ʼ����Ŀǰ�������Ĺ�����ü��� */
#define WLAN_CONFIG_VAP_MAX_NUM_PER_DEVICE      1   /* ����VAP����,һ��ҵ��deviceһ�� */
#define WLAN_SERVICE_VAP_MAX_NUM_PER_DEVICE     4   /* ҵ��VAP����(ԭ��Ӧ����AP����+STA�����������ʾоƬ���֧������  */


/* ÿ��device֧��vap��������=���ҵ��VAP��Ŀ+����VAP���� */
/* �������:P2P_dev/CL��STAģʽ���ڣ�P2P_GO��APģʽ����
    1)AP ģʽ:  2��ap + 1������vap
    2)STA ģʽ: 3��sta + 1������vap
    3)STA+P2P����ģʽ:  1��sta + 1��P2P_dev + 1��P2P_GO/Client + 1������vap
    4)Ԥ��һ����NAN
*/

/* 4��ҵ��VAP + 1������vap */
#define WLAN_VAP_MAX_NUM_PER_DEVICE_LIMIT         (WLAN_CONFIG_VAP_MAX_NUM_PER_DEVICE + WLAN_SERVICE_VAP_MAX_NUM_PER_DEVICE)

/* ����BOARD֧�ֵ�����VAP��Ŀ */
#define WLAN_VAP_SUPPORT_MAX_NUM_LIMIT            (WLAN_SERVICE_DEVICE_SUPPORT_MAX_NUM_SPEC * WLAN_VAP_MAX_NUM_PER_DEVICE_LIMIT)

/* ����BOARD֧�ֵ����ҵ��VAP����Ŀ */
#define WLAN_SERVICE_VAP_SUPPORT_MAX_NUM_LIMIT    (WLAN_SERVICE_DEVICE_SUPPORT_MAX_NUM_SPEC * (WLAN_VAP_MAX_NUM_PER_DEVICE_LIMIT - WLAN_CONFIG_VAP_MAX_NUM_PER_DEVICE))

/* ����������Ա���Զ��ƻ�: WLAN_ASSOC_USER_MAX_NUM��Ӧg_us_assoc_max_user��WLAN_ACTIVE_USER_MAX_NUM��Ӧg_us_active_max_user */
/* �����û��������� */
#define WLAN_ASSOC_USER_MAX_NUM                    10  /* �����û��������� */

/* ��Ծ�û��������� */
#define WLAN_ACTIVE_USER_MAX_NUM                   10

/* ��Ծ�û�����λͼ���� */
#define WLAN_ACTIVE_USER_IDX_BMAP_LEN      ((WLAN_ACTIVE_USER_MAX_NUM + 7)>> 3)
/* �����û�����λͼ���� */
#define WLAN_ASSOC_USER_IDX_BMAP_LEN       ((WLAN_ASSOC_USER_MAX_NUM + 7)>> 3)
/* �����õ�RA LUT IDX */
#define WLAN_INVALID_RA_LUT_IDX             WLAN_ACTIVE_USER_MAX_NUM

/* ���������û���񣬱�ʾ����֧�������; ��֮��Ӧ����MAC_RES_XXX(���ڵ���RES_XXX)��Ϊ���ƻ��õ�����ӦWLAN_ASSOC_USER_MAX_NUMΪg_us_assoc_max_user */
/* ʹ�ù���:������������oal oam hal��ʼ����Ա�����������±꣬��֮��Ӧmac res�ĵ������鲥���Լ���board user�������װ�ɺ�����ҵ��������� */
/*board�������û��� = 1��CHIP֧�ֵ��������û��� * board�����CHIP��Ŀ*/
#define WLAN_ASOC_USER_MAX_NUM_LIMIT       (WLAN_ASSOC_USER_MAX_NUM * WLAN_CHIP_MAX_NUM_PER_BOARD)

/* board�鲥�û��� */
#define WLAN_MULTI_USER_MAX_NUM_LIMIT      (WLAN_SERVICE_VAP_SUPPORT_MAX_NUM_LIMIT)

/*board����û��� = �������û��� + �鲥�û����� */
#define WLAN_USER_MAX_USER_LIMIT           (WLAN_ASOC_USER_MAX_NUM_LIMIT + WLAN_MULTI_USER_MAX_NUM_LIMIT)

/* alg�㷨ģ��ʹ��,ָ��user index,�������鲥�û���,��user lut index������ */
#define WLAN_ALG_ASOC_USER_NUM_LIMIT       (WLAN_ASOC_USER_MAX_NUM_LIMIT)

/*****************************************************************************
  2.2 WLANЭ���Ӧ��spec
*****************************************************************************/

/*****************************************************************************
  2.3 oam��ص�spec
*****************************************************************************/
#if (((_PRE_OS_VERSION_WIN32 == _PRE_OS_VERSION)||(_PRE_OS_VERSION_WIN32_RAW == _PRE_OS_VERSION)) || (_PRE_OS_VERSION_WINDOWS == _PRE_OS_VERSION))
#define WLAN_OAM_FILE_PATH      "C:\\OAM.log"                   /* WIN32��WINDOWS��,LOG�ļ�Ĭ�ϵı���λ�� */
#elif ((_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION) || (_PRE_OS_VERSION_RAW == _PRE_OS_VERSION))
#define WLAN_OAM_FILE_PATH      "\\home\\oam.log"               /* LINUX����ϵͳ��,LOG�ļ�Ĭ�ϵı���λ�� */
#endif

/*****************************************************************************
  2.4 mem��Ӧ��spec
*****************************************************************************/
/*****************************************************************************
  2.4.1
*****************************************************************************/

#define WLAN_MEM_MAX_BYTE_LEN               (65000 + 1)   /* �ɷ�������ڴ�鳤�� 03��������*/
#define WLAN_MAX_MAC_HDR_LEN                     36           /* ����macͷ���� oal_mem.h�������øú� */

#if (_PRE_OS_VERSION_RAW == _PRE_OS_VERSION) || (_PRE_OS_VERSION_WIN32_RAW == _PRE_OS_VERSION)
#define WLAN_MEM_MAX_SUBPOOL_NUM            6             /* ��ϵͳ�ڴ���г�netbuf�ڴ����������ڴ�ظ��� */
#else
#define WLAN_MEM_MAX_SUBPOOL_NUM            8             /* �ڴ����������ڴ�ظ��� */
#endif
#define WLAN_MEM_MAX_USERS_NUM              4             /* ����ͬһ���ڴ������û��� */

/*****************************************************************************
  2.4.2 �����������ڴ��������Ϣ
*****************************************************************************/
/* ����device����TID�����MPDU��������
    ��Ҫ���¶��壬��֧�ֵ����߼�
*/
#define WLAN_TID_MPDU_NUM_BIT               9
#define WLAN_TID_MPDU_NUM_LIMIT             (1 << WLAN_TID_MPDU_NUM_BIT)

#define WLAN_MEM_SHARED_RX_DSCR_SIZE        68              /*��ʵ�ʽ����������ṹ���Դ�Щ��Ԥ��������Խ������������޸�*/
#ifdef _PRE_WLAN_FEATURE_MULTI_NETBUF_AMSDU                              /*��MAC amsdu��������ذ汾������򿪸ú�*/
#define WLAN_MEM_SHARED_TX_DSCR_SIZE1       112             /*PILOT amsdu����8���ֽ�*/
#define WLAN_MEM_SHARED_TX_DSCR_SIZE2       112             /*PILOT amsdu����8���ֽ�*/
#else
#define WLAN_MEM_SHARED_TX_DSCR_SIZE1       104             /*��ʵ�ʷ����������ṹ���Դ�Щ��Ԥ��������Է������������޸�*/
#define WLAN_MEM_SHARED_TX_DSCR_SIZE2       104             /*��ʵ�ʷ����������ṹ���Դ�Щ��Ԥ��������Է������������޸�*/
#endif

#if defined(_PRE_DEBUG_MODE)
#define WLAN_MEM_SHARED_RX_DSCR_CNT         110             /* ����512(����֡������) + 64(����֡������) */ /* ע��! ����һ�����ڴ��Ҫ����oal_mem.c���OAL_MEM_BLK_TOTAL_CNT */
#define WLAN_MEM_SHARED_TX_DSCR_CNT1        172             /* ����������512 */
#define WLAN_MEM_SHARED_TX_DSCR_CNT2        0               /* ����amsdu�������� */
#else
#define WLAN_MEM_SHARED_RX_DSCR_CNT         0
#define WLAN_MEM_SHARED_TX_DSCR_CNT1        0
#define WLAN_MEM_SHARED_TX_DSCR_CNT2        0
#endif

#define TOTAL_WLAN_MEM_SHARED_DSCR_SIZE     ((WLAN_MEM_SHARED_RX_DSCR_SIZE + OAL_MEM_INFO_SIZE + OAL_DOG_TAG_SIZE)*WLAN_MEM_SHARED_RX_DSCR_CNT \
                                            + (WLAN_MEM_SHARED_TX_DSCR_SIZE1 + OAL_MEM_INFO_SIZE + OAL_DOG_TAG_SIZE)*WLAN_MEM_SHARED_TX_DSCR_CNT1 \
                                            + (WLAN_MEM_SHARED_TX_DSCR_SIZE2 + OAL_MEM_INFO_SIZE + OAL_DOG_TAG_SIZE)*WLAN_MEM_SHARED_TX_DSCR_CNT2)

/*****************************************************************************
  2.4.3 ��������֡�ڴ��������Ϣ
*****************************************************************************/
#define WLAN_MEM_SHARED_MGMT_PKT_SIZE1      800
#if (_PRE_OS_VERSION_LINUX == _PRE_OS_VERSION)
#define WLAN_MEM_SHARED_MGMT_PKT_CNT1       0  /* �˳�����hostʹ�ò��� */
#else
#define WLAN_MEM_SHARED_MGMT_PKT_CNT1       1  /* �˳����� UT ��ʹ�� */
#endif

#define TOTAL_WLAN_MEM_SHARED_MGMT_PKT_SIZE ((WLAN_MEM_SHARED_MGMT_PKT_SIZE1 + OAL_MEM_INFO_SIZE + OAL_DOG_TAG_SIZE)*WLAN_MEM_SHARED_MGMT_PKT_CNT1)

/*****************************************************************************
  2.4.4 ��������֡�ڴ��������Ϣ
*****************************************************************************/
#define WLAN_MEM_SHARED_DATA_PKT_SIZE       44              /* 80211mac֡ͷ��С */
#define WLAN_MEM_SHARED_DATA_PKT_CNT        200             /* skb(���յ�֡ͷ����) + ��������������(���͵�֡ͷ����) 768 */

#define TOTAL_WLAN_MEM_SHARED_DATA_PKT_SIZE ((WLAN_MEM_SHARED_DATA_PKT_SIZE + OAL_MEM_INFO_SIZE + OAL_DOG_TAG_SIZE)*WLAN_MEM_SHARED_DATA_PKT_CNT)

/*****************************************************************************
  2.4.5 �����ڴ��������Ϣ
*****************************************************************************/
#define WLAN_MEM_LOCAL_SIZE1                32
/*4+12+4 for event queue*/
#define WLAN_MEM_LOCAL_CNT1                 (69+4+12+4)     /* 256(32*8)��dmac_alg_tid_stru + 256��alg_tid_entry_stru + 5���¼�����(NON_RESET_ERR)*/

#ifdef _PRE_WLAN_FEATURE_PROXYSTA
#define WLAN_MEM_LOCAL_SIZE2                144
#define WLAN_MEM_LOCAL_CNT2                 800             /* 200(����) */
#else
#define WLAN_MEM_LOCAL_SIZE2                104
#define WLAN_MEM_LOCAL_CNT2                 50              /* 200(����) */
#endif

#define WLAN_MEM_LOCAL_SIZE3                264             /* �洢hmac_vap_cfg_priv_stru��ÿ��VAPһ�� + �¼����� FRW_EVENT_TYPE_BUTT * WLAN_VAP_SUPPORT_MAX_NUM_LIMIT  */

/* ����WL_L2_DRAM��С���ƣ�Ŀǰ��ʱ����2��ҵ��vap�������񿪷Ŵ������Ż� TBD */
#if (_PRE_OS_VERSION_RAW == _PRE_OS_VERSION) || (_PRE_OS_VERSION_WIN32_RAW == _PRE_OS_VERSION)
/*��ϵͳ��Ӧ�����ڴ����*/
#define WLAN_MEM_LOCAL_CNT3                 (WLAN_VAP_SUPPORT_MAX_NUM_LIMIT + 60)/* ��Դ�س�ʼ����Ҫ1�� +1 */
#else
/*Linuxϵͳ��Ӧ�����ڴ��������Ҫ�����¼����еĸ���*/
#define WLAN_MEM_LOCAL_CNT3                 (WLAN_VAP_SUPPORT_MAX_NUM_LIMIT + 60)
#endif

#define WLAN_MEM_LOCAL_SIZE4                512             /* ����Ϊ128���¼������� */
#define WLAN_MEM_LOCAL_CNT4                 (20+36)         /*36 for event queue*/

#define WLAN_MEM_LOCAL_SIZE5                4304
#define WLAN_MEM_LOCAL_CNT5                 64

#define WLAN_MEM_LOCAL_SIZE6                16000           /* ��Դ���û���ʼ��ʹ�� */
#define WLAN_MEM_LOCAL_CNT6                 0               /* Ŀǰ0Ƭ*/
/*****************************************************************************
  2.4.6 ���ٱ����ڴ��(����TCM��)������Ϣ
*****************************************************************************/

/*****************************************************************************
  2.4.6 �¼��ṹ���ڴ��
*****************************************************************************/
#define WLAN_MEM_EVENT_SIZE1                72              /* ע��: �¼��ڴ泤�Ȱ���4�ֽ�IPCͷ���� */
#define WLAN_MEM_EVENT_SIZE2                528             /* ע��: �¼��ڴ泤�Ȱ���4�ֽ�IPCͷ���� */

#if (_PRE_OS_VERSION_RAW == _PRE_OS_VERSION) || (_PRE_OS_VERSION_WIN32_RAW == _PRE_OS_VERSION)
/*��ϵͳ��Ӧ�����ڴ����*/
#define WLAN_MEM_EVENT_CNT1                 180
#define WLAN_MEM_EVENT_CNT2                 8   /* 03 APUTʱ��������02��һ����ɾ���û���֤���¼�������
                                                   ����������¼��Ƿ���Ҫ�Ż�ʹ�õ�һƬ */

#else
/*Linuxϵͳ��Ӧ�����ڴ��������Ҫ�����¼����д�С*/
#define WLAN_MEM_EVENT_CNT1                 (180 * WLAN_FRW_MAX_NUM_CORES)
#define WLAN_MEM_EVENT_CNT2                 8   /* 03 APUTʱ��������02��һ����ɾ���û���֤���¼�������
                                                   ����������¼��Ƿ���Ҫ�Ż�ʹ�õ�һƬ */
#endif

#define WLAN_WPS_IE_MAX_SIZE                608   /*03�������*/
#ifdef _PRE_WLAN_FEATURE_HILINK
#define WLAN_OKC_IE_MAX_SIZE                WLAN_MEM_EVENT_SIZE2 - 32   /* 32��ʾ�¼�����ռ�õĿռ� */
#endif
#ifdef _PRE_WLAN_FEATURE_M2S
#define WLAN_M2S_IE_MAX_SIZE                WLAN_WPS_IE_MAX_SIZE
#endif

/*****************************************************************************
  2.4.7 �û��ڴ��
*****************************************************************************/
/*****************************************************************************
  2.4.8 MIB�ڴ��  TBD :���ո��ӳصĿռ��С��������Ҫ���¿���
*****************************************************************************/
#define WLAN_MEM_MIB_SIZE1                  1320           /* mib�ṹ���С */
#define WLAN_MEM_MIB_CNT1                   WLAN_SERVICE_VAP_SUPPORT_MAX_NUM_LIMIT /* ԭ��Ϊ((WLAN_VAP_SUPPORT_MAX_NUM_LIMIT - 1) * 2) */ /* ����VAPû��MIB */
#if (WLAN_VAP_SUPPORT_MAX_NUM_LIMIT < (WLAN_CONFIG_VAP_MAX_NUM_PER_DEVICE* WLAN_CHIP_MAX_NUM_PER_BOARD * WLAN_DEVICE_MAX_NUM_PER_CHIP))
#error invaild WLAN_MEM_MIB_CNT1
#endif
/*****************************************************************************
  2.4.9 netbuf�ڴ��  TBD :���ո��ӳصĿռ��С��������Ҫ���¿���
*****************************************************************************/

#if ((_PRE_OS_VERSION_RAW == _PRE_OS_VERSION)||(_PRE_OS_VERSION_WIN32_RAW == _PRE_OS_VERSION))
#define  WLAN_MEM_NETBUF_SIZE1              180     /* ��֡netbufpayload���� */
#define  WLAN_MEM_NETBUF_CNT1               70     /* ��֡netbufpayload����2 */

#define  WLAN_MEM_NETBUF_SIZE2              800     /* ����֡netbufpayload���� */
#if (_PRE_OS_VERSION_RAW == _PRE_OS_VERSION)
#define  WLAN_MEM_NETBUF_CNT2               8      /* ����֡netbufpayload���� 8*/
#elif (_PRE_OS_VERSION_WIN32_RAW == _PRE_OS_VERSION)
#define  WLAN_MEM_NETBUF_CNT2               16      /* �������������й���֡�ڴ棬UT���Թ黹�����ʼ����һ�£�����UT�����ڴ������й©�������ⲻ������ */
#endif

#define  WLAN_MEM_NETBUF_SIZE3              1568    /* ��֡netbufpayload���� */
#define  WLAN_MEM_NETBUF_CNT3               176     /* ��֡netbufpayload���� */

#define  WLAN_MEM_NETBUF_SIZE4              512     /* SDT �ڴ�س��� */
#define  WLAN_MEM_NETBUF_CNT4               4       /* SDT �ڴ���� */

#define  OAL_NETBUF_MACHDR_BYTE_LEN         64      /* netbuf macͷ���� */

#define WLAN_LARGE_NETBUF_SIZE        WLAN_MEM_NETBUF_SIZE3 /* NETBUF�ڴ�س�֡�ĳ��ȣ�ͳһ������� */
#define WLAN_MGMT_NETBUF_SIZE         WLAN_MEM_NETBUF_SIZE2 /* NETBUF�ڴ�ع���֡�ĳ��ȣ�ͳһ������� */
#define WLAN_SHORT_NETBUF_SIZE        WLAN_MEM_NETBUF_SIZE1 /* NETBUF�ڴ�ض�֡�ĳ��ȣ�ͳһ������� */
#define WLAN_SDT_NETBUF_SIZE          WLAN_MEM_NETBUF_SIZE4 /* NETBUF�ڴ��SDT�ĳ��ȣ�ͳһ������� */

#define WLAN_MAX_NETBUF_SIZE         (WLAN_LARGE_NETBUF_SIZE + WLAN_MAX_MAC_HDR_LEN)  /* netbuf���֡����֡ͷ + payload */

#else
#define WLAN_MEM_NETBUF_SIZE1               0       /* ��¡��SKB */
#define WLAN_MEM_NETBUF_CNT1                192     /* ��������֡��AMSDU�����е�ÿ��MSDU��Ӧһ����¡netbuf */

#ifndef _PRE_WLAN_PHY_PERFORMANCE
#define WLAN_MEM_NETBUF_SIZE2               1600    /* 1500 + WLAN_MAX_FRAME_HEADER_LEN(36) + WLAN_HDR_FCS_LENGTH(4) + (����ʧ�ܵĻ�,�����ֶ�Ҳ���ϱ�(20)) */
#define WLAN_MEM_NETBUF_CNT2                512     /* ����192(��������֡) + 32(���չ���֡) + 32(���͹���֡) */
                                                            /* ���ǽ���wlan2wlanת��������������Ļ�����x2 */
#define WLAN_MEM_NETBUF_SIZE3               2500    /* ���Ƭ�����鱨�ĵ�skb */
#define WLAN_MEM_NETBUF_CNT3                32      /* ��Ծ�û�ÿ���û�һ�� */

#else
#define WLAN_MEM_NETBUF_SIZE2               5100
#define WLAN_MEM_NETBUF_CNT2                512

#define WLAN_MEM_NETBUF_SIZE3               5100    /* ���Ƭ�����鱨�ĵ�skb */
#define WLAN_MEM_NETBUF_CNT3                32      /* ��Ծ�û�ÿ���û�һ�� */
#endif

#define  WLAN_MEM_NETBUF_SIZE4              512     /* SDT �ڴ�س��� */
#define  WLAN_MEM_NETBUF_CNT4               4       /* SDT �ڴ���� */

#define WLAN_LARGE_NETBUF_SIZE        WLAN_MEM_NETBUF_SIZE2   /* NETBUF�ڴ�س�֡�ĳ��ȣ�ͳһ������� */
#define WLAN_MGMT_NETBUF_SIZE         WLAN_MEM_NETBUF_SIZE2   /* NETBUF�ڴ�ع���֡�ĳ��ȣ�ͳһ������� */
#define WLAN_SHORT_NETBUF_SIZE        WLAN_MEM_NETBUF_SIZE2   /* NETBUF�ڴ�ض�֡�ĳ��ȣ�ͳһ������� */
#define WLAN_MAX_NETBUF_SIZE          WLAN_LARGE_NETBUF_SIZE  /* netbuf���֡����֡ͷ + payload */
#define WLAN_SDT_NETBUF_SIZE          WLAN_MEM_NETBUF_SIZE4   /* NETBUF�ڴ��SDT�ĳ��ȣ�ͳһ������� */

#endif

#define WLAN_MEM_NETBUF_ALIGN               4       /* netbuf���� */
#define WLAN_MEM_ETH_HEADER_LEN             14      /* ��̫��֡ͷ���� */

/*****************************************************************************
  2.4.9.1 sdt netbuf�ڴ��
*****************************************************************************/

/*  sdt��ϢԤ������ڴ�飬��netbuf��Ӻ󣬹������г���ʱ����Ҫ���⴦����ֱ��send����
    �ⲿ�������볤��ΪPayload�ĳ���
*/
/************************* sdt report msg format*********************************/
/* NETLINK_HEAD     | SDT_MSG_HEAD  | Payload    | SDT_MSG_TAIL  |    pad       */
/* ---------------------------------------------------------------------------- */
/* NLMSG_HDRLEN     |    8Byte      |     ...    |   1Byte       |    ...       */
/********************************************************************************/
#define WLAN_SDT_SKB_HEADROOM_LEN       8
#define WLAN_SDT_SKB_TAILROOM_LEN       1
#define WLAN_SDT_SKB_RESERVE_LEN        (WLAN_SDT_SKB_HEADROOM_LEN + WLAN_SDT_SKB_TAILROOM_LEN)

/*
    SDT�ڴ����Ҫ����SDT��Ϣ��ʵ�ʽ��е���
*/
#define WLAN_MEM_SDT_NETBUF_PAYLOAD1            37          //��־��Ϣ����
#define WLAN_MEM_SDT_NETBUF_PAYLOAD2            100
#define WLAN_MEM_SDT_NETBUF_PAYLOAD3            512
#define WLAN_MEM_SDT_NETBUF_PAYLOAD4            1600

#define WLAN_SDT_NETBUF_MAX_PAYLOAD             WLAN_MEM_SDT_NETBUF_PAYLOAD4

#define WLAN_MEM_SDT_NETBUF_SIZE1       (WLAN_MEM_SDT_NETBUF_PAYLOAD1 + WLAN_SDT_SKB_RESERVE_LEN)
#define WLAN_MEM_SDT_NETBUF_SIZE1_CNT   250
#define WLAN_MEM_SDT_NETBUF_SIZE2       (WLAN_MEM_SDT_NETBUF_PAYLOAD2 + WLAN_SDT_SKB_RESERVE_LEN)
#define WLAN_MEM_SDT_NETBUF_SIZE2_CNT   250
#define WLAN_MEM_SDT_NETBUF_SIZE3       (WLAN_MEM_SDT_NETBUF_PAYLOAD3 + WLAN_SDT_SKB_RESERVE_LEN)
#define WLAN_MEM_SDT_NETBUF_SIZE3_CNT   250
#define WLAN_MEM_SDT_NETBUF_SIZE4       (WLAN_MEM_SDT_NETBUF_PAYLOAD4 + WLAN_SDT_SKB_RESERVE_LEN)
#define WLAN_MEM_SDT_NETBUF_SIZE4_CNT   256

#define WLAN_SDT_MSG_FLT_HIGH_THD           800
#define WLAN_SDT_MSG_QUEUE_MAX_LEN          (WLAN_MEM_SDT_NETBUF_SIZE1_CNT + \
                                                     WLAN_MEM_SDT_NETBUF_SIZE2_CNT + \
                                                     WLAN_MEM_SDT_NETBUF_SIZE3_CNT + \
                                                     WLAN_MEM_SDT_NETBUF_SIZE4_CNT - 6)  /* ��������ڴ��Ҫ�٣��˴�ȡ��1000 */

/*****************************************************************************
  2.4.10 RFͨ��������ѷ���WLAN_SPEC
*****************************************************************************/

/*****************************************************************************
  2.4.11 TCP ACK�Ż�
*****************************************************************************/
/* tcp ack���˹��ܲ���Ĭ�ϴ򿪣������������� */
#define DEFAULT_TX_TCP_ACK_OPT_ENABLE (OAL_FALSE)
#define DEFAULT_RX_TCP_ACK_OPT_ENABLE (OAL_FALSE)
#define DEFAULT_TX_TCP_ACK_THRESHOLD (1) /*��������ack ������*/
#define DEFAULT_RX_TCP_ACK_THRESHOLD (1) /*��������ack ������*/
/*****************************************************************************
  2.5 frw��ص�spec
*****************************************************************************/


/******************************************************************************
    �¼�����������Ϣ��
    ע��: ÿ�������������ɵ�����¼�����������2����������
*******************************************************************************/
/*host event cfg table*/
#define FRW_EVENT_MAX_NUM_QUEUES    (FRW_EVENT_TYPE_BUTT * WLAN_VAP_SUPPORT_MAX_NUM_LIMIT)

#define WLAN_FRW_EVENT_CFG_TABLE_PER_VAP \
    /* �¼�����       ����Ȩ��   �����������ɵ�����¼�����   �����������Ȳ��� */  \
    /* HIGH_PRIO */     {   1,               32,                      0, 0}, \
    /* HOST_CRX */      {   1,               64,                      1, 0}, \
    /* HOST_DRX */      {   1,               64,                      1, 0}, \
    /* HOST_CTX */      {   1,               64,                      1, 0}, \
    /* HOST_SDT */      {   1,               64,                      1, 0}, \
    /* WLAN_CRX */      {   1,               64,                      1, 0}, \
    /* WLAN_DRX */      {   1,               64,                      1, 0}, \
    /* WLAN_CTX */      {   1,               64,                      1, 0}, \
    /* WLAN_DTX */      {   1,               64,                      1, 0}, \
    /* WLAN_TX_COMP */  {   1,                0,                      1, 0}, \
    /* TBTT */          {   1,                0,                      1, 0}, \
    /* TIMEOUT */       {   1,                2,                      1, 0}, \
    /* HMAC MISC */     {   1,                0,                      1, 0}, \
    /* DMAC MISC */     {   1,               64,                      0, 0},

/*Host, double device */
#define WLAN_FRW_EVENT_CFG_TABLE \
  { \
    WLAN_FRW_EVENT_CFG_TABLE_PER_VAP \
    WLAN_FRW_EVENT_CFG_TABLE_PER_VAP \
    WLAN_FRW_EVENT_CFG_TABLE_PER_VAP \
    WLAN_FRW_EVENT_CFG_TABLE_PER_VAP \
    WLAN_FRW_EVENT_CFG_TABLE_PER_VAP \
    WLAN_FRW_EVENT_CFG_TABLE_PER_VAP \
    WLAN_FRW_EVENT_CFG_TABLE_PER_VAP \
    WLAN_FRW_EVENT_CFG_TABLE_PER_VAP \
  }

/*****************************************************************************
  2.8.0 ����OS����
*****************************************************************************/

/*****************************************************************************
  2.9 DFT
*****************************************************************************/
/*****************************************************************************
  2.9.0 ��־
*****************************************************************************/
/*****************************************************************************
  2.9.15 WiFi�ؼ���Ϣ���
*****************************************************************************/



/*****************************************************************************
  3 ö�ٶ���
*****************************************************************************/

/*****************************************************************************
  4 ȫ�ֱ�������
*****************************************************************************/


/*****************************************************************************
  5 ��Ϣͷ����
*****************************************************************************/


/*****************************************************************************
  6 ��Ϣ����
*****************************************************************************/


/*****************************************************************************
  7 STRUCT����
*****************************************************************************/


/*****************************************************************************
  8 UNION����
*****************************************************************************/


/*****************************************************************************
  9 OTHERS����
*****************************************************************************/


/*****************************************************************************
  10 ��������
*****************************************************************************/
#endif /* #if ((_PRE_PRODUCT_ID == _PRE_PRODUCT_ID_HI1103_DEV) || (_PRE_PRODUCT_ID == _PRE_PRODUCT_ID_HI1103_HOST))*/

#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* #ifndef __PLATFORM_SPEC_1103_H__ */


