/******************************************************************
 *
 * uEcho for C
 *
 * Copyright (C) Satoshi Konno 2015
 *
 * This is licensed under BSD-style license, see file COPYING.
 *
 ******************************************************************/

#include <uecho/controller.h>

/****************************************
 * uecho_controller_new
 ****************************************/

uEchoController *uecho_controller_new()
{
	uEchoController *cp;

  cp = (uEchoController *)malloc(sizeof(uEchoController));

  if (!cp)
    return NULL;

  cp->mutex = uecho_mutex_new();
  cp->server = uecho_server_new();
  
  uecho_controller_setlasttid(cp, 0);
  
	return cp;
}

/****************************************
 * uecho_object_delete
 ****************************************/

void uecho_controller_delete(uEchoController *cp)
{
	uecho_controller_stop(cp);
	
	uecho_mutex_delete(cp->mutex);
  uecho_server_delete(cp->server);

  free(cp);
}

/****************************************
 * uecho_controller_start
 ****************************************/

bool uecho_controller_start(uEchoController *cp)
{
	return true;
}

/****************************************
 * uecho_controller_stop
 ****************************************/

bool uecho_controller_stop(uEchoController *cp)
{
	return true;
}

/****************************************
 * uecho_controller_isrunning
 ****************************************/

bool uecho_controller_isrunning(uEchoController *cp)
{
	return true;
}

/****************************************
 * uecho_controller_getnexttid
 ****************************************/

uEchoTID uecho_controller_getnexttid(uEchoController *cp) {
  if (uEchoTidMax <= cp->lastTID) {
    cp->lastTID = 1;
  }
  else {
    cp->lastTID++;
  }
  return cp->lastTID;
}

/****************************************
 * uecho_controller_searchall
 ****************************************/

bool uecho_controller_searchall(uEchoController *cp) {
    byte nodeProfileObj[3] = {0x0E, 0xF0, 0x01};
    return true;
}

/****************************************
 * uecho_controller_searchobject
 ****************************************/

bool uecho_controller_searchobject(uEchoController *cp) {
    return true;
}
