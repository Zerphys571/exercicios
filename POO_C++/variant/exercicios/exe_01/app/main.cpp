#include <iostream>
#include "main.hpp"

int
main(void)
{
  CasaInteligente casa;
  Lampada l1;
  Termostato t1;
  SensorPorta sensor;

  l1.ligar();
  l1.setBrilho(80);

  t1.setTemperatura(18);

  sensor.fechar();

  casa.adicionarDispositivo(l1);
  casa.adicionarDispositivo(t1);
  casa.adicionarDispositivo(sensor);

  casa.gerarRelatorio();

  casa.AtivarModoInverno();

  casa.gerarRelatorio();

  return EXIT_SUCCESS;
}