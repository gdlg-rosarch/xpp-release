# Script generated with Bloom
pkgdesc="ROS - Visualization for the XPP Motion Framework."
url='http://github.com/leggedrobotics/xpp'

pkgname='ros-lunar-xpp-vis'
pkgver='1.0.5_1'
pkgrel=1
arch=('any')
license=('BSD'
)

makedepends=('ros-lunar-catkin'
'ros-lunar-kdl-parser'
'ros-lunar-robot-state-publisher'
'ros-lunar-roscpp'
'ros-lunar-tf'
'ros-lunar-visualization-msgs'
'ros-lunar-xpp-msgs'
'ros-lunar-xpp-states'
)

depends=('ros-lunar-kdl-parser'
'ros-lunar-robot-state-publisher'
'ros-lunar-roscpp'
'ros-lunar-tf'
'ros-lunar-visualization-msgs'
'ros-lunar-xpp-msgs'
'ros-lunar-xpp-states'
)

conflicts=()
replaces=()

_dir=xpp_vis
source=()
md5sums=()

prepare() {
    cp -R $startdir/xpp_vis $srcdir/xpp_vis
}

build() {
  # Use ROS environment variables
  source /usr/share/ros-build-tools/clear-ros-env.sh
  [ -f /opt/ros/lunar/setup.bash ] && source /opt/ros/lunar/setup.bash

  # Create build directory
  [ -d ${srcdir}/build ] || mkdir ${srcdir}/build
  cd ${srcdir}/build

  # Fix Python2/Python3 conflicts
  /usr/share/ros-build-tools/fix-python-scripts.sh -v 2 ${srcdir}/${_dir}

  # Build project
  cmake ${srcdir}/${_dir} \
        -DCMAKE_BUILD_TYPE=Release \
        -DCATKIN_BUILD_BINARY_PACKAGE=ON \
        -DCMAKE_INSTALL_PREFIX=/opt/ros/lunar \
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

