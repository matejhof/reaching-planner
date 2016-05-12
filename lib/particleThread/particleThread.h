/* 
 * Copyright: (C) 2015 iCub Facility - Istituto Italiano di Tecnologia
 * Author: Alessandro Roncone <alessandro.roncone@iit.it>
 * website: www.robotcub.org
 * author website: http://alecive.github.io
 * 
 * Permission is granted to copy, distribute, and/or modify this program
 * under the terms of the GNU General Public License, version 2 or any
 * later version published by the Free Software Foundation.
 *
 * A copy of the license can be found at
 * http://www.robotcub.org/icub/license/gpl.txt
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
 * Public License for more details.
*/

#ifndef __PARTICLETHREAD_H__
#define __PARTICLETHREAD_H__

#include <yarp/os/Time.h>
#include <yarp/os/RateThread.h>
#include <yarp/os/Log.h>
#include <yarp/os/Mutex.h>
#include <yarp/os/LockGuard.h>

#include <yarp/sig/Vector.h>
#include <yarp/sig/Matrix.h>

#include <yarp/math/Math.h>

#include <iCub/ctrl/math.h>
#include <iCub/ctrl/pids.h>

#include <stdarg.h>

using namespace std;

class particleThread: public yarp::os::RateThread
{
protected:
    /***************************************************************************/
    // EXTERNAL VARIABLES: change them from command line or through .ini file
    // Flag that manages verbosity (v=1 -> more text printed out; v=2 -> even more text):
    int verbosity;
    // Name of the module (to change port names accordingly):
    string name;

    /***************************************************************************/
    // INTERNAL VARIABLES:
    // Integrator to get the particle trajectory
    iCub::ctrl::Integrator *integrator;

    // Speed of the particle in 3D
    yarp::sig::Vector vel;

    // Mutex for handling things correctly
    yarp::os::Mutex mutex;

    // Variable to turn the particleThread on or off
    bool isRunning;

    /**
    * Prints a message according to the verbosity level:
    * @param l is the level of verbosity: if level > verbosity, something is printed
    * @param f is the text. Please use c standard (like printf)
    */
    int printMessage(const int l, const char *f, ...) const;

public:
    // CONSTRUCTOR
    particleThread(int , const string & , int );
    // RUN
    virtual void run();
    // RELEASE
    virtual void threadRelease();

    /**
    * Initializes the integrator to a new particle to track.
    * @return true/false on success/failure.
    **/
    bool setupNewParticle(const yarp::sig::Vector &, const yarp::sig::Vector &);

    /**
    * Stops the particle motion.
    * @return true/false on success/failure.
    **/
    bool stopParticle();

    /**
    * Resets the particle at a given state
    * @param  _x_0 the state
    * @return true/false on success/failure.
    **/
    bool resetParticle(const yarp::sig::Vector &_x_0);

    /**
    * Gets the current state of the particle.
    * @return the particle 3D position.
    **/
    yarp::sig::Vector getParticle();
};

#endif

