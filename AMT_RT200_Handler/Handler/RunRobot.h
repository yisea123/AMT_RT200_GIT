#pragma once
#include "Variable.h"

class CRunRobot
{
public:
	CRunRobot(void);
	~CRunRobot(void);
	
	
public:
	int				m_nRunStep;
	int             m_nFeederStep;
	int				m_nInitStep;
	int				m_nRdimmJobState;
	bool			m_bPickUpDnFlag[2];
	bool			m_bCylFlag[2];

	DWORD			m_dwPickUpDnWaitTime[2][3];
	DWORD			m_dwWRejectCylWaitTime[2][3]; //kwlee 2017.0216

	int				m_npTemp_Picker_YesNo[MAX_PICKCNT]; 
	int				m_nLinearMove_Index;
	int             m_nPickCnt;
	int             m_nPickerNum;
	int             mn_Retry;
	double          m_dPitch_x;
	double          m_dPitch_Y;
	int             m_nCnt;
	int             m_nVaccumCnt;
	int             m_nRobot_Z;
	int             m_nRobot_T;
	int             m_nRobot_P;
	int             m_nRobot_X;
	int             m_nRobot_Y;
	int             m_nCntBcrNum;
	int             m_nMove_Flag[5];
	int             m_nJobNextPos; //kwlee 2016.1229
	CString         m_strBarcode[2];
	int             m_nPrintOutCheck;
	int             m_nBarcodeReadCheck[2];
	int             m_nBcrRetryCnt[2];
	//kwlee 2017.0204
	int             m_nPrintOutPutCnt;
	int             m_nEmptyCntBufferCnt;
	CString         m_strPrintSerial[2];
	int             m_nLabelFailCheck;
	CString			m_strAlarmCode;	
	double			m_dpTargetPosList[4];
	double			m_dpSpdRatio[3]; 
	long			m_lAxisCnt;              //현재의 IndexNum에서 사용 가능한 모터 수량 최대 4개  
	long			m_lpAxisNum[4];	         //현재의 IndexNum에서 사용하는 모터 실재 번호를 가진다 
	DWORD           m_dwTimeCheck[3];
	DWORD           m_dwBcrTime[3];
	bool            m_bSecondPos;
	bool            m_PickSecondPOs;
	int             m_nInterFaceStep;
	int             m_nLabelReq;
	long            m_lFeederWaitTime[3];
	long            m_lVaccumOffTime[3];
	long            m_lTurnConvWaitTime[3];
	
public:
	void	OnThreadRUN();
	void	OnRunInit();
	void    OnRobotRun();
	void	OnSetPickerUpDn(int nMode, int nOnOff, int *npPickerInfo);
	int		OnGetPickerUpDn(int nMode, int nOnOff, int *npPickerInfo);
	void    OnSetRejectCylUpDn(int nMode, int nUpDn);
	int     OnGetRejectCylUpDn(int nMode, int nUpDn);
	int	    OnFeederInterface();
	void    OnFeederReq(int nStep);
	void    OnSelectPickType(int nType);
	int     GetIntefaceInfo(int mStep) { return m_nInterFaceStep == mStep; }
	void    SetInterfaceStep(int mStep) { m_nInterFaceStep = mStep; }
	
	void    OnSetLabelPick(int nMode, int nPickCnt);
	//void    OnSetLabelPlace(int nPickCnt);
	void    OnSetLabelPlace(int nPickCnt);
	void    OnVaccummSet(int nMode, int nPickCnt,int OnOff);
	//void    OnBlowSet(int OnOff);
	void    OnBlowSet(int nMode, int nPickCnt , int OnOff);
	void    OnGetPickCheck(int nMode, int nPickCnt);
	
	int     OnGetVaccumgmCheck(int OnOff,int nPickCnt);
	//void    OnDataExchange(int nPickPlace);
	void    OnDataExchange(int nMode, int nPickPlace);
	int     OnPrinterFeeder(int nCnt, int nFailCheck);
    int    OnBufferDataTransfer(int nCnt);
	int     OnFailLabelCheck();
	void    OnBarcodeReadCheck();
	void    OnResetRejectData();
};

extern CRunRobot	clsRunRobot;