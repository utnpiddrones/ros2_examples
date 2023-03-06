from setuptools import setup
import os
from glob import glob

package_name = 'python_package'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name), glob('launch/*launch.[pxy][yma]*'))
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='cotti',
    maintainer_email='cotti@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],

    # Agregar todos los ejecutables
    #   <package_name>.<file_name>:<function_name>
    entry_points={
        'console_scripts': [
            "pub = python_package.publisher:main",
            "sub = python_package.subscriber:main",
            "service = python_package.service:main",
            "client = python_package.client:main",
        ],
    },
)
