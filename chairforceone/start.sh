#!/bin/bash

echo "=========================="
echo "Starting App chairforceone for {APP_NAME_PRETTY}"


systemctl start chairforceone
systemctl start rosnodeChecker
