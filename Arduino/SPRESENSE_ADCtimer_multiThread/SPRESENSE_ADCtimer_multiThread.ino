void setup() {
  Serial.begin(115200);


  const char *argv0[1];
  //const char *argv1[3];
  //char play_no0[4];
  //char play_no1[4];

  //snprintf(play_no0, 4, "%d", AS_PLAYER_ID_0);
  //snprintf(play_no1, 4, "%d", AS_PLAYER_ID_1);

  argv0[0] = "pass this";
//  argv0[1] = PLAY0_FILE_NAME;
//  argv0[2] = NULL;
//  argv1[0] = play_no1;
//  argv1[1] = PLAY1_FILE_NAME;
//  argv1[2] = NULL;

  /* Start task */
  /****************************************************************************
     from task_create.c:

      This function creates and activates a new task with a specified
      priority and returns its system-assigned ID.

      The entry address entry is the address of the "main" function of the
      task.  This function will be called once the C environment has been
      set up.  The specified function will be called with four arguments.
      Should the specified routine return, a call to exit() will
      automatically be made.

      Note that four (and only four) arguments must be passed for the spawned
      functions.

     Input Parameters:
      name       - Name of the new task
      priority   - Priority of the new task
      stack_size - size (in bytes) of the stack needed
      entry      - Entry point of a new task
      arg        - A pointer to an array of input parameters. Up to
                   CONFIG_MAX_TASK_ARG parameters may be provided.  If fewer
                   than CONFIG_MAX_TASK_ARG parameters are passed, the list
                   should be terminated with a NULL argv[] value. If no
                   parameters are required, argv may be NULL.

     Return Value:
      Returns the non-zero process ID of the new task or ERROR if memory is
      insufficient or the task cannot be created.  The errno will be set to
      indicate the nature of the error (always ENOMEM).

  ****************************************************************************/
  // task_create(name, priority, stack_size, entry, arguments)
  task_create("player_thread0", 155, 2048, ADC_timing, (char* const*)argv0);
//  task_create("player_thread1", 155, 2048, ADC_timing, (char* const*)argv1);
}

void loop() {
  // put your main code here, to run repeatedly:

}

static int ADC_timing(FAR char *argv[])
{

}
