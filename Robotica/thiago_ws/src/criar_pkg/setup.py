from setuptools import find_packages, setup

package_name = 'criar_pkg'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='mhsp',
    maintainer_email='souza.passos990@gmail.com',
    description='TODO: Package description',
    license='Apache-2.0',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
            'cmd_thiago = criar_pkg.control_thiago:main',
            'laser_test = criar_pkg.process_laser:main',
            'arm_controller = criar_pkg.control_arm:main',
            'head_controller = criar_pkg.control_head:main',
            'image_test = criar_pkg.process_image:main'

        ],
    },
)
