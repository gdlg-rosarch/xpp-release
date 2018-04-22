# Script generated with Bloom
pkgdesc="ROS - Xpp is collection of packages for the visualization of motion plans for floating-base robots. Apart from drawing support areas, contact forces and motion trajectories in RVIZ, it also displays these plans for specific robots. Current robots include a one-legged, a two-legged hopper, <a href="http://dls.iit.it/">HyQ</a> and a quadrotor."
url='http://github.com/leggedrobotics/xpp'

pkgname='ros-kinetic-xpp'
pkgver='1.0.5_1'
pkgrel=1
arch=('any')
license=('BSD'
)

makedepends=('ros-kinetic-catkin'
)

depends=('ros-kinetic-xpp-examples'
'ros-kinetic-xpp-hyq'
'ros-kinetic-xpp-msgs'
'ros-kinetic-xpp-quadrotor'
'ros-kinetic-xpp-states'
'ros-kinetic-xpp-vis'
)

conflicts=()
replaces=()

_dir=xpp
source=()
md5sums=()

prepare() {
    cp -R $startdir/xpp $srcdir/xpp
}

build() {
  # Use ROS environment variables
  source /usr/share/ros-build-tools/clear-ros-env.sh
  [ -f /opt/ros/kinetic/setup.bash ] && source /opt/ros/kinetic/setup.bash

  # Create build directory
  [ -d ${srcdir}/build ] || mkdir ${srcdir}/build
  cd ${srcdir}/build

  # Fix Python2/Python3 conflicts
  /usr/share/ros-build-tools/fix-python-scripts.sh -v 2 ${srcdir}/${_dir}

  # Build project
  cmake ${srcdir}/${_dir} \
        -DCMAKE_BUILD_TYPE=Release \
        -DCATKIN_BUILD_BINARY_PACKAGE=ON \
        -DCMAKE_INSTALL_PREFIX=/opt/ros/kinetic \
        -DPYTHON_EXECUTABLE=/usr/bin/python2 \
        -DPYTHON_INCLUDE_DIR=/usr/include/python2.7 \
        -DPYTHON_LIBRARY=/usr/lib/libpython2.7.so \
        -DPYTHON_BASENAME=-python2.7 \
        -DSETUPTOOLS_DEB_LAYOUT=OFF
  make
}

package() {
  cd "${srcdir}/build"
  make DESTDIR="${pkgdir}/" install
}

