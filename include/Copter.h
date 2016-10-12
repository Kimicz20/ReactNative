// Definition of the RCInput class

#ifndef Copter_class
#define Copter_class

#include "RCInput.h"
#include "SupportClass.h"
class Copter {
public:
	
	RCInput rc_input;
	//
	SupportClass supt;
	int flight_mode;
	union {
		struct {
			int unused1 : 1; // 0
			int simple_mode : 2; // 1,2     // This is the state of simple mode : 0 = disabled ; 1 = SIMPLE ; 2 = SUPERSIMPLE
			int pre_arm_rc_check : 1; // 3       // true if rc input pre-arm checks have been completed successfully
			int pre_arm_check : 1; // 4       // true if all pre-arm checks (rc, accel calibration, gps lock) have been performed
			int auto_armed : 1; // 5       // stops auto missions from beginning until throttle is raised
			int logging_started : 1; // 6       // true if dataflash logging has started
			int land_complete : 1; // 7       // true if we have detected a landing
			bool new_radio_frame ; // 8       // Set true if we have new PWM data to act on from the Radio
			int rc_receiver_present : 1; // 10      // true if we have an rc receiver present (i.e. if we've ever received an update
			int compass_mot : 1; // 11      // true if we are currently performing compassmot calibration
			int motor_test : 1; // 12      // true if we are currently performing the motors test
			int initialised : 1; // 13      // true once the init_ardupilot function has completed.  Extended status to GCS is not sent until this completes
			int land_complete_maybe : 1; // 14      // true if we may have landed (less strict version of land_complete)
			bool throttle_zero; // 15      // true if the throttle stick is at zero, debounced, determines if pilot intends shut-down when not using motor interlock
			int system_time_set : 1; // 16      // true if the system time has been set from the GPS
			int gps_base_pos_set : 1; // 17      // true when the gps base position has been set (used for RTK gps only)
			//enum HomeState home_state : 2; // 18,19   // home status (unset, set, locked)
			int using_interlock : 1; // 20      // aux switch motor interlock function is in use
			int motor_emergency_stop : 1; // 21      // motor estop switch, shuts off motors when enabled
			int land_repo_active : 1; // 22      // true if the pilot is overriding the landing position
		};
		int value;
	} ap;

	// Failsafe
	struct {
		int rc_override_active : 1; // 0   // true if rc control are overwritten by ground station
		bool radio ; // 1   // A status flag for the radio failsafe
		int battery : 1; // 2   // A status flag for the battery failsafe
		int gcs : 1; // 4   // A status flag for the ground station failsafe
		int ekf : 1; // 5   // true if ekf failsafe has occurred
		int radio_counter;            // number of iterations with throttle below throttle_fs_value
		int last_heartbeat_ms;      // the time when the last HEARTBEAT message arrived from a GCS - used for triggering gcs failsafe
	} failsafe;
	
	void rc_loop();
	void throttle_loop();	
	void set_failsafe_radio(bool b);
	void set_failsafe_battery(bool b);
	float get_smoothing_gain();	
	void failsafe_radio_on_event();
	void failsafe_radio_off_event();
	void update_events();
	bool set_mode(int mode);
	void update_flight_mode();
	void exit_mode(int old_control_mode, int new_control_mode);	
	bool mode_has_manual_throttle(int mode);
	bool mode_allows_arming(int mode, bool arming_from_gcs);
	void arm_motors_check();
	void auto_disarm_check();
	void read_radio();
	void read_control_switch();
	void set_throttle_and_failsafe(int throttle_pwm);
	void set_throttle_zero_flag(int throttle_control);
	void init_ardupilot();
};

#endif