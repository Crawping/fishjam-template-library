#pragma once

/*************************************************************************************************
* ����filter��ý�����ݵ��ڴ�ռ����ͨ�����;�������䣺�ڶ��ϡ���DirectDraw���棨surface�����ڹ���GDI�ڴ��ʹ�������ķ�����ơ�
* 
* Pinʹ�õĵ�MediaSample����Э��(�������ӵ�Pin��,������һ��Pin�ṩһ����������Pin������Э�̷����������Ļ�������ÿ������ĳߴ�)
*   CBaseOutputPin::CompleteConnect
*     ->DecideAllocator(Э���ڴ������)
*       ->InputPin::GetAllocatorRequirements(��ȡ����Pin�ϵ�����)
*       ->InputPin::GetAllocator (���Ȼ�ȡ����Pin�ķ�����������ɹ��򷵻�)
*       ->DecideBufferSize(���Pin����������أ���������m_mt��ȷ��ʹ�õķ���������--�ڴ��С��ʹ�õ�
*         Sample������--ͨ�� IMemAllocator::SetProperties ����)
*       ->InputPin::NotifyAllocator(�ɹ�������������Pin��NotifyAllocator֪ͨ����ʹ�õķ�����)
*       �������Pin���ṩ�������������÷�����ʧ��
*       ->InitAllocator(�����Pin������׼�ķ���������ִ����ͬ���߼�)
*         DecideBufferSize->InputPin::NotifyAllocator)
*
* IMemAllocator -- ��������ڴ�ռ�, ���� IMediaSample ���ڴ�أ�ͨ�� GetBuffer ���ؿ���ʹ�õ�IMediaSample��
*   ���е�Filter���ͷ���Samle�󣬲��ܷ��ظ��������Ļ����
*     (����Ҫ�����filter�б���IMediaSample��ָ��?����Ҫ�첽�������ݣ���Ҫ�������ü�����������Ϻ��ټ���)
*   ʹ�����ü����Ļ��Ƽ������ܵ��ڴ�������(�����ظ�ʹ��ͬ���Ļ���)�����ҷ�ֹ�������ڱ�����ǰ����ر�����д�롣
* IMemInputPin -- ��ע�⣺���Ǵ�IPin�ϼ̳У����� IMemAllocator�����ܽ��� IMediaSample
* IMediaSample
*************************************************************************************************/