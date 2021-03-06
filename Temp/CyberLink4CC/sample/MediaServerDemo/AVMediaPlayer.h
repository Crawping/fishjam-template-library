#pragma once

#include <cybergarage/upnp/CyberLink.h>
#include <cybergarage/upnp/media/player/MediaPlayer.h>

class IAVMediaPlayerCallback
{
public:
    virtual void OnDeviceAdded(CyberLink::Device *dev) = 0;
    virtual void OnDeviceRemoved(CyberLink::Device* dev) = 0;
};

class CAVMediaPlayer 
	: public CyberLink::MediaPlayer
	, public CyberLink::NotifyListener
	, public CyberLink::EventListener
	, public CyberLink::SearchResponseListener
    , public CyberLink::DeviceChangeListener

{
public:
	CAVMediaPlayer(IAVMediaPlayerCallback* pCallback);
	~CAVMediaPlayer(void);

	void DumpInfo();

	//virtual HTTP::StatusCode httpRequestRecieved( HTTPRequest *httpReq );
	virtual void deviceNotifyReceived( CyberLink::SSDPPacket *ssdpPacket );
	virtual void eventNotifyReceived( const std::string &uuid, long seq, const std::string &varName, const std::string &value );
	virtual void deviceSearchResponseReceived( CyberLink::SSDPPacket *ssdpPacket );

    virtual void deviceAdded(CyberLink::Device *dev);
    virtual void deviceRemoved(CyberLink::Device *dev);
private:
	IAVMediaPlayerCallback* m_pCallback;

};
