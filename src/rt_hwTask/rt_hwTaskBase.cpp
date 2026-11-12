#include "rt_hwTaskBase.h"

FlprogRtHwTask::FlprogRtHwTask(uint8_t type)
{
  setType(type);
}

FlprogRtHwTask::~FlprogRtHwTask()
{
  delete _task;
}

// Создаём сначала новую задачу, затем удаляем старую. При неизвестном коде
// текущую задачу сохраняем, а при первичной инициализации она останется пустой.
void FlprogRtHwTask::setType(uint8_t type)
{
  FlprogAbstractRtHwTask *next = nullptr;
  switch (type)
  {
  case FLPROG_TASK_EXTERNAL_CHNGED_EVENT_SKIP: next = new FlprogRtHwTaskC(); break;
  case FLPROG_TASK_EXTERNAL_CHNGED: next = new FlprogRtHwTaskQ(); break;
  case FLPROG_TASK_COMAND_START: next = new FlprogRtHwTaskE(); break;
  case FLPROG_TASK_ONE_TIME_START: next = new FlprogRtHwTaskF(); break;
  case FLPROG_TASK_EVERY_CYCLE_START: next = new FlprogRtHwTaskR(); break;
  case FLPROG_TASK_PERIODIK_EVENT_SKIP: next = new FlprogRtHwTaskP(); break;
  case FLPROG_TASK_PERIODIK_SECONDS_EVENT_SKIP: next = new FlprogRtHwTaskPS(); break;
  case FLPROG_TASK_EXTERNAL_CHNGED_AND_PERIODIK_EVENT_SKIP: next = new FlprogRtHwTaskT(); break;
  case FLPROG_TASK_EXTERNAL_CHNGED_OR_PERIODIK_EVENT_SKIP: next = new FlprogRtHwTaskA(); break;
  default: return;
  }
  delete _task;
  _task = next;
}

// Передаём параметры выбранной реализации; до setType() вызов безопасен.
void FlprogRtHwTask::setQntPass(uint8_t qntPass)
{
  if (_task)
  {
    _task->setQntPass(qntPass);
  }
}

void FlprogRtHwTask::setPeriod(uint16_t period)
{
  if (_task)
  {
    _task->setPeriod(period);
  }
}

uint8_t FlprogRtHwTask::direct(uint8_t extEN)
{
  if (_task)
  {
    return _task->direct(extEN);
  }
  return 0;
}

uint8_t FlprogRtHwTask::run()
{
  if (_task)
  {
    return _task->run();
  }
  return 0;
}

bool FlprogRtHwTask::canWork()
{
  if (_task)
  {
    return _task->canWork();
  }
  return false;
}

void FlprogRtHwTask::reset()
{
  if (_task)
  {
    _task->reset();
  }
}

void FlprogRtHwTask::run(uint8_t value)
{
  if (_task)
  {
    _task->run(value);
  }
}