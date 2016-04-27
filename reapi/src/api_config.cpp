#include "precompiled.h"

CAPI_Config api_cfg;

CAPI_Config::CAPI_Config() : m_api_rehlds(false), m_api_regame(false), m_api_vtc(false)
{

}

void CAPI_Config::Init()
{
	m_api_rehlds = RehldsApi_Init();
	m_api_regame = RegamedllApi_Init();
	m_api_vtc    = VTC_Api_Init();
}

void CAPI_Config::ServerActivate() const
{
	if (m_api_regame) {
		g_pCSGameRules = (CHalfLifeMultiplay **)g_ReGameApi->GetGameData()->GetGameRules();
	}
}

void CAPI_Config::ServerDeactivate() const
{
	if (m_api_regame) {
		g_pCSGameRules = nullptr;
	}
}
