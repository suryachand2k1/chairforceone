#!/bin/bash

echo "=========================="
echo "Removing App chairforceone"


LIBPANDA_USER=$(cat /etc/libpanda.d/libpanda_usr)

# Disable the installed services:
echo " - Disabling startup scripts..."
systemctl disable chairforceone


# Here is where we remove scripts, services, etc.
echo " - Removing scripts..."
cd
if [ "x"`systemctl list-units | grep -c chairforceone.service` = "x1" ]; then
    echo "Uninstalling chairforceone.service"

    source /home/$LIBPANDA_USER/catkin_ws/devel/setup.bash
    rosrun robot_upstart uninstall chairforceone
fi

systemctl daemon-reload # if needed
