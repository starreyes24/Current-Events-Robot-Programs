#pragma config(Motor,  port2,           drive,         tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           servo,         tmotorServoStandard, openLoop)
#pragma config(Motor,  port5,           armOne,        tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port6,           armTwo,        tmotorServoStandard, openLoop)
//*!! Code automatically generated by 'ROBOTC' configuration wizard !!*//

task move()
{// Moves the robot forwards and backwards //

	while(true)
	{

		int driveVar = vexRT[Ch3];// sets "driveVar" to current value of joystick axis "Ch3" //
		motor(drive) = driveVar;// sets motor speed to value of "driveVar" //

	}

}


task armRotate()
{// Rotates the robot's arm in a semi-circle horizontally //

	while(true)
	{

		int servoVal = vexRT[Ch4];// sets "servoVal" to current value of joystick axis "Ch4" //
		motor(servo) = servoVal;// sets servo position to value of "servoVal" //

	}

}


task armJoint()
{// Changes the positions of the robot's first arm joint to provide more maneuverability //

	while(true)
	{

		if(vexRT[Btn8U])// If button 8U is being pressed, set motor armOne's speed to 127 //
		{

			motor[armOne] = 127;

		}
		else// If button 8U is NOT being pressed, stop motor armOne //
		{

			motor[armOne] = 0;

		}

		if(vexRT[Btn8D])// If button 8D is being pressed, set motor armOne's speed to -127(backwards version of previous if-else statement) //
		{

			motor[armOne] = -127;

		}
		else// If button 8D is NOT currently pressed, stop motor armOne //
		{

			motor[armOne] = 0;

		}

	}

}


task otherJoint()
{// Changes the position of the robot's second arm joint to provide more maneuverability //

	while(true)
	{

		if(vexRT[Btn7U])// If button 7U is being pressed, set motor armTwo's speed to 127 //
		{

			motor[armTwo] = 127;

		}
		else// If button 7U is NOT being pressed, stop motor armTwo //
		{

			motor[armTwo] = 0;

		}

		if(vexRT[Btn7D])// If button 7D is being pressed, set motor armTwo's speed to -127(backwards version of previous if-else statement) //
		{

			motor[armTwo] = -127;

		}
		else// If button 7D is NOT being pressed, stop motor armTwo //
		{

			motor[armTwo] = 0;

		}

	}

}


task motorRotate()
{// Will move motor 360* clockwise with one button, and 360* counter-clockwise with another button //

	while(true)// Program will constantly check for these events //
	{
		if(vexRT[Btn5U])// If Btn5U is pressed, rotate motor "drive" 360 degrees clockwise //
		{

			moveMotor(drive, 1, rotations, 127);

		}
		else// If Btn5U is NOT pressed, check for next event //
		{

			if(vexRT[Btn6U])// If Btn6U is pressed, rotate motor "drive" 360 degrees counter-clockwise //
			{

				moveMotor(drive, 1, rotations, -127);

			}
			else// If none of these events are triggered, stop motor "drive" //
			{

				stopMotor(drive);

			}

		}

	}

}


task main()
{// Runs all subtasks //

	while(true)
	{

		startTask(move);// Task for moving robot (lines 8-19) //
		startTask(armRotate);// Task for rotating arm (lines 22-33) //
		startTask(armJoint);// Task for moving first arm joint (lines 36-70) //
		startTask(otherJoint);// Task for moving second arm joint (lines 73-107) //
		startTask(motorRotate);// Task for moving robot forwards or backwards one "space" (lines 110-141) //

	}

}
