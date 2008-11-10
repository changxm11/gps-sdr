/*! \file OBJECT.cpp
	Implements member functions of OBJECT class.
*/
/************************************************************************************************
Copyright 2008 Gregory W Heckler

This file is part of the GPS Software Defined Radio (GPS-SDR)

The GPS-SDR is free software; you can redistribute it and/or modify it under the terms of the
GNU General Public License as published by the Free Software Foundation; either version 2 of the
License, or (at your option) any later version.

The GPS-SDR is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without
even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License along with GPS-SDR; if not,
write to the:

Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
************************************************************************************************/

#include "OBJECT.h"

/*----------------------------------------------------------------------------------------------*/
void *OBJECT_Thread(void *_arg)
{

	OBJECT *aOBJECT = pOBJECT;

	while(grun)
	{
		aOBJECT->Import();
		aOBJECT->Export();
	}

	pthread_exit(0);

}
/*----------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------*/
void OBJECT::Start()
{
	pthread_create(&thread, NULL, OBJECT_Thread, NULL);
	printf("OBJECT thread started\n");
}
/*----------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------*/
void OBJECT::Stop()
{
	pthread_cancel(thread);
	pthread_join(thread, NULL);
	printf("OBJECT thread stopped\n");
}
/*----------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------*/
OBJECT::OBJECT()
{

	pthread_mutex_init(&mutex, NULL);
	pthread_mutex_unlock(&mutex);

	temp = 0;

}
/*----------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------*/
OBJECT::~OBJECT()
{

	pthread_mutex_destroy(&mutex);

	printf("Destructing OBJECT\n");

}
/*----------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------*/
void OBJECT::Import()
{

}
/*----------------------------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------------------------*/
void OBJECT::Export()
{

}
/*----------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------*/
void OBJECT::Lock()
{
	pthread_mutex_lock(&mutex);
}
/*----------------------------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------------------------*/
void OBJECT::Unlock()
{
	pthread_mutex_unlock(&mutex);
}
/*----------------------------------------------------------------------------------------------*/


