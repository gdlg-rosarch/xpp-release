# Script generated with Bloom
pkgdesc="ROS - The URDF file for a quadrotor to be used with the xpp packages and a simple rviz publisher of quadrotor tfs. Adapted from Daniel Mellinger, Nathan Michael, Vijay Kumar, &quot;Trajectory Generation and Control for Precise Aggressive Maneuvers with Quadrotors&quot;."
url='http://github.com/leggedrobotics/xpp'

pkgname='ros-kinetic-xpp-quadrotor'
pkgver='1.0.5_1'
pkgrel=1
arch=('any')
license=('BSD'
)

makedepends=('ros-kinetic-catkin'
'ros-kinetic-roscpp'
'ros-kinetic-xpp-vis'
)

depends=('ros-kinetic-roscpp'
'ros-kinetic-xpp-vis'
)

conflicts=()
replaces=()

_dir=xpp_quadrotor
source=()
md5sums=()

prepare() {
    cp -R $startdir/xpp_quadrotor $srcdir/xpp_quadrotor
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

