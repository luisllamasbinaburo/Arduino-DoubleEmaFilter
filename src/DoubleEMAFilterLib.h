/***************************************************
Copyright (c) 2017 Luis Llamas
(www.luisllamas.es)

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License
 ****************************************************/

#ifndef _DoubleEMAFilterLib_h
#define _DoubleEMAFilterLib_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

template <typename T>
class DoubleEMAFilter
{
public:
	DoubleEMAFilter<T>(const double alpha1, const double alpha2);
	void AddValue(const T value);
	T GetBandPass();
	T GetBandStop();

private:
	double _alphaLow;
	double _alphaHigh;

	T _lowPassFilterLow;
	T _lowPassFilterHigh;
	T _bandPassFilter;
	T _bandStopFilter;
};

template<typename T>
DoubleEMAFilter<T>::DoubleEMAFilter(const double alpha1, const double alpha2)
{
	this->_alphaLow = alpha1 < alpha2 ? alpha1 : alpha2;
	this->_alphaHigh = alpha1 >= alpha2 ? alpha1 : alpha2;
}

template<typename T>
void DoubleEMAFilter<T>::AddValue(const T value)
{
	this->_lowPassFilterLow = (T)(this->_alphaLow * value + (1 - this->_alphaLow) * this->_lowPassFilterLow);
	this->_lowPassFilterHigh = (T)(this->_alphaHigh * value + (1 - this->_alphaHigh) * this->_lowPassFilterHigh);
	this->_bandPassFilter = this->_lowPassFilterHigh - this->_lowPassFilterLow;
	this->_bandStopFilter = value - this->_bandPassFilter;
}

template<typename T>
inline T DoubleEMAFilter<T>::GetBandPass()
{
	return this->_bandPassFilter;
}

template<typename T>
inline T DoubleEMAFilter<T>::GetBandStop()
{
	return this->_bandStopFilter;
}
#endif

