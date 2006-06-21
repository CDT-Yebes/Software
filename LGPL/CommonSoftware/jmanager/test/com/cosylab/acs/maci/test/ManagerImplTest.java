/*
 * @@COPYRIGHT@@
 */
package com.cosylab.acs.maci.test;

import java.net.URI;
import java.net.URISyntaxException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import javax.naming.Context;

import org.omg.CORBA.ORB;

import EDU.oswego.cs.dl.util.concurrent.CyclicBarrier;
import EDU.oswego.cs.dl.util.concurrent.SynchronizedBoolean;
import EDU.oswego.cs.dl.util.concurrent.SynchronizedInt;
import abeans.core.Identifier;
import abeans.core.Root;
import abeans.core.UnableToInstallComponentException;
import abeans.core.defaults.ExceptionIgnorer;
import abeans.framework.ApplicationContext;
import abeans.framework.FrameworkLayer;
import abeans.models.meta.AbeansDirectory;
import abeans.models.meta.TargetPart;
import abeans.pluggable.acs.CORBAService;
import abeans.pluggable.acs.DefaultCORBAService;

import com.cosylab.acs.cdb.CDBAccess;
import com.cosylab.acs.maci.ComponentSpec;
import com.cosylab.acs.maci.ComponentSpecIncompatibleWithActiveComponentException;
import com.cosylab.acs.maci.Container;
import com.cosylab.acs.maci.ContainerInfo;
import com.cosylab.acs.maci.Administrator;
import com.cosylab.acs.maci.BadParametersException;
import com.cosylab.acs.maci.Component;
import com.cosylab.acs.maci.ComponentInfo;
import com.cosylab.acs.maci.ComponentStatus;
import com.cosylab.acs.maci.Client;
import com.cosylab.acs.maci.ClientInfo;
import com.cosylab.acs.maci.HandleConstants;
import com.cosylab.acs.maci.IncompleteComponentSpecException;
import com.cosylab.acs.maci.IntArray;
import com.cosylab.acs.maci.InvalidComponentSpecException;
import com.cosylab.acs.maci.NoDefaultComponentException;
import com.cosylab.acs.maci.NoPermissionException;
import com.cosylab.acs.maci.NoResourcesException;
import com.cosylab.acs.maci.StatusHolder;
import com.cosylab.acs.maci.StatusSeqHolder;
import com.cosylab.acs.maci.manager.CURLHelper;
import com.cosylab.acs.maci.manager.ComponentInfoTopologicalSort;
import com.cosylab.acs.maci.manager.ManagerImpl;
import com.cosylab.lifecycle.LifecyclePhase;
import com.cosylab.lifecycle.LifecycleReporterSupport;

import junit.framework.TestCase;
import junit.framework.TestSuite;

/**
 * ManagerImpl tests.
 * 
 * @author Jernej Kamenik
 * @author Matej Sekoranja
 * @version @@VERSION@@
 */
public class ManagerImplTest extends TestCase
{
	private ApplicationContext ctx;
	private ManagerImplTestEngine app;
	
	public class ManagerImplTestEngine
		extends LifecycleReporterSupport
		implements abeans.framework.ApplicationEngine
	{
		private Identifier id = new IdentifierImpl();
	
		private class IdentifierImpl implements Identifier
		{
			private String name = null;
			private String shortName = null;
			private String qualifiedShortName = null;
			private String qualifiedLongName = null;
			private short type = Identifier.APPLICATION;
			//private Node parent = null;
			public IdentifierImpl()
			{
				this.name = "ManagerImplTestEngine";
				this.shortName = "MngTestEng";
				this.type = Identifier.APPLICATION;
	
			}
			public String getName()
			{
				return name;
			}
			public String getShortName()
			{
				return shortName;
			}
			public String getQualifiedLongName()
			{
				if (qualifiedLongName == null)
				{
					qualifiedLongName = "ManagerImplTestEngine";
				}
				return qualifiedLongName;
			}
			public String getQualifiedShortName()
			{
				if (qualifiedShortName == null)
				{
					qualifiedShortName = "ManagerImplTestEngine";
				}
				return qualifiedShortName;
			}
			public short getType()
			{
				return type;
			}
		}
	
		public ManagerImplTestEngine()
		{
			super(null, false, LifecyclePhase.INITIALIZED);
		}
		public javax.swing.JApplet getApplet()
		{
			return null;
		}
		public abeans.core.Identifier getIdentifier()
		{
			return id;
		}
		public java.lang.String getModelName()
		{
			//return "Channel";
			return null;
		}
		public boolean isDebug()
		{
			return false;
		}
		public void shutdown()
		{
			try
			{
				fireDestroying();
			}
			catch (Exception e)
			{
				e.printStackTrace();
				fail();
			}
			try
			{
				fireDestroyed();
			}
			catch (Exception e)
			{
				e.printStackTrace();
				fail();
			}
		}
	}

	/******************************************************************************/

	//final String domain = "testDomain";
	final String cobName = "testCOB";
	final String clientName = "testClient";
	final String containerName = "testContainer";
	final String administratorName = "testAdministrator";
	final String anotherName = "anotherClient";
	final String type = "non-null";
	final String uri = "invalid";
	final int dummyHandle = Integer.MAX_VALUE/2;
	ManagerImpl manager;

    final int STARTUP_COBS_SLEEP_TIME_MS = 6000;
    final int SLEEP_TIME_MS = 3000;
	
	URI dummyURI=null;

	/**
	 * Constructor for ManagerImplTest
	 * 
	 * @param arg0
	 */
	public ManagerImplTest(String arg0)
	{
		super(arg0);

		try
		{
			dummyURI = new URI(uri);
		}
		catch (URISyntaxException usi)
		{ 
			fail(usi.toString());
		}
	}
	
	/**
	 * @see junit.framework.TestCase#setUp()
	 */
	protected void setUp() throws Exception
	{
		//
		// set ${abeans.home} configuration directory to TestConfig
		//
		/*
		final String filePrefix = "file:/";
		
		URL url = this.getClass().getClassLoader().getResource("TestConfig");
		if (url!=null)
		{
			String configDir = url.toString();
			if (configDir!=null && configDir.startsWith(filePrefix))
			{
				configDir = configDir.substring(filePrefix.length());
				System.getProperties().setProperty("abeans.home", configDir);
			}
		}
		*/

		app = new ManagerImplTestEngine();
		ctx = FrameworkLayer.registerApplication(app);
		
		Context c = new AbeansDirectory(TargetPart.SCHEMA);
		manager = new ManagerImpl();
		
		ORB orb = null;
        try {
            if (Root.getComponentManager().getComponent(CORBAService.class) == null)
                    Root.getComponentManager().installComponent(DefaultCORBAService.class);
            orb = ((DefaultCORBAService) Root.getComponentManager().getComponent(CORBAService.class)).getORB();
        }
        catch (UnableToInstallComponentException e) {
        	e.printStackTrace();
        	fail();
        }
		
		manager.initialize(null, null, new CDBAccess(orb), c);
		//manager.setDomain(domain);
	
		manager.setApplicationContext(ctx);

		// test abeans startup
		assertTrue(Root.isInitialized());
	}

	/**
	 * @see junit.framework.TestCase#tearDown()
	 */
	protected void tearDown() throws Exception
	{
		if (manager != null)
		{
			manager.shutdown(HandleConstants.MANAGER_MASK, 0);
			manager = null;
		}

		if (app != null)
			app.shutdown();

		// sleep do complete the shutdown
		Thread.sleep(1000);

		// test abeans shutdown
		assertTrue(!Root.isInitialized());
		
	}

	
	public void testAbeansFrameworkStartupShutdown() throws Exception
	{
		for (int i = 0; i < 4; i++)
		{
			tearDown();
			setUp();
		}
	}
	
	
	/**
	 * 
	 * Test of ManagerImpl shutdown.
	 *
	 */
	public void testShutdown()
	{
		
		try
		{
			manager.shutdown(0, 0);
			fail();
		}
		catch (NoPermissionException npe)
		{
			new ExceptionIgnorer(npe);
			System.out.println("This is OK: "+npe.getMessage());
		}

		Client client = new TestClient(clientName);		
		ClientInfo info = manager.login(client);
		try
		{
			manager.shutdown(info.getHandle(), 0);
			fail();
		}
		catch (NoPermissionException npe)
		{
			new ExceptionIgnorer(npe);
			System.out.println("This is OK: "+npe.getMessage());
		}

		Administrator admin = new TestAdministrator("shutdownAdmin");		
		ClientInfo info2 = manager.login(admin);
		manager.shutdown(info2.getHandle(), 0);

		// already shutdown
		try
		{
			manager.shutdown(info2.getHandle(), 0);
			fail();
		}
		catch (NoPermissionException npe)
		{
			new ExceptionIgnorer(npe);
			System.out.println("This is OK: "+npe.getMessage());
		}

		// already shutdown
		try
		{
			manager.logout(info.getHandle());
			fail();
		}
		catch (NoPermissionException npe)
		{
			new ExceptionIgnorer(npe);
			System.out.println("This is OK: "+npe.getMessage());
		}

		// already shutdown
		try
		{
			manager.login(client);
			fail();
		}
		catch (NoPermissionException npe)
		{
			new ExceptionIgnorer(npe);
			System.out.println("This is OK: "+npe.getMessage());
		}

		// tearDown should not shutdown
		manager = null;
	}

	public void testContainerShutdown()
	{
		
		try
		{
			manager.shutdownContainer(0, null, 0);
			fail();
		}
		catch (BadParametersException bpe)
		{
			new ExceptionIgnorer(bpe);
			System.out.println("This is OK: "+bpe.getMessage());
		}

		try
		{
			manager.shutdownContainer(0, "test", 0);
			fail();
		}
		catch (NoPermissionException npe)
		{
			new ExceptionIgnorer(npe);
			System.out.println("This is OK: "+npe.getMessage());
		}

		Client client = new TestClient(clientName);		
		ClientInfo info = manager.login(client);
		try
		{
			manager.shutdownContainer(info.getHandle(), "test", 0);
			fail();
		}
		catch (NoPermissionException npe)
		{
			new ExceptionIgnorer(npe);
			System.out.println("This is OK: "+npe.getMessage());
		}

		Administrator admin = new TestAdministrator("shutdownAdmin");		
		ClientInfo info2 = manager.login(admin);

		try
		{
			manager.shutdownContainer(info2.getHandle(), null, 0);
			fail();
		}
		catch (BadParametersException bpe)
		{
			new ExceptionIgnorer(bpe);
			System.out.println("This is OK: "+bpe.getMessage());
		}

		try
		{
			manager.shutdownContainer(info2.getHandle(), "invalid", 0);
			fail();
		}
		catch (NoResourcesException nre)
		{
			new ExceptionIgnorer(nre);
			System.out.println("This is OK: "+nre.getMessage());
		}


		TestContainer container = new TestContainer("Container");
		Map supportedComponents = new HashMap();
		TestComponent mount1COB = new TestComponent("MOUNT1");
		supportedComponents.put("MOUNT1", mount1COB);
		container.setSupportedComponents(supportedComponents);

		ClientInfo containerInfo = manager.login(container);

		try { Thread.sleep(STARTUP_COBS_SLEEP_TIME_MS); } catch (InterruptedException ie) {}

		// test activated Components
		ComponentInfo[] infos = manager.getComponentInfo(info.getHandle(), new int[0], "*", "*", true);
		assertEquals(1, infos.length);
		
		try
		{
			manager.shutdownContainer(info.getHandle(), "Container", 0);
			fail();
		}
		catch (NoPermissionException npe)
		{
			new ExceptionIgnorer(npe);
			System.out.println("This is OK: "+npe.getMessage());
		}
		
		//manager.shutdownContainer(info2.getHandle(), "Container", /* special code */);
		//assertEquals(1, container.getActivatedComponents().size());
		
		manager.shutdownContainer(info2.getHandle(), "Container", 1);
		assertEquals(0, container.getActivatedComponents().size());
	}

	
	public void testLogin()
	{
	
		// test null
		try
		{
			manager.login(null);
			fail();
		}
		catch (BadParametersException bpe)
		{
			new ExceptionIgnorer(bpe);
			System.out.println("This is OK: "+bpe.getMessage());
		}

		// test null name
		try
		{
			manager.login(new TestClient(null));
			fail();
		}
		catch (BadParametersException bpe)
		{
			new ExceptionIgnorer(bpe);
			System.out.println("This is OK: "+bpe.getMessage());
		}

		// test null autheticate
		try
		{
			manager.login(new TestClient("null-auth", null));
			fail();
		}
		catch (BadParametersException bpe)
		{
			new ExceptionIgnorer(bpe);
			System.out.println("This is OK: "+bpe.getMessage());
		}

		// test invalid autheticate
		try
		{
			manager.login(new TestClient("invalid-auth", "invalid"));
			fail();
		}
		catch (NoPermissionException npe)
		{
			new ExceptionIgnorer(npe);
			System.out.println("This is OK: "+npe.getMessage());
		}

		// test invalid autheticate
		try
		{
			manager.login(new TestClient("container-invalid-auth", "A"));
			fail();
		}
		catch (NoPermissionException npe)
		{
			new ExceptionIgnorer(npe);
			System.out.println("This is OK: "+npe.getMessage());
		}
		
		//test client login
		Client client = new TestClient(clientName);		
		ClientInfo info = manager.login(client);

		assertNotNull(info);
		assertTrue((info.getHandle() & HandleConstants.CLIENT_MASK) == HandleConstants.CLIENT_MASK);
		assertEquals(info.getClient(),client);

		//test duplicate login
		ClientInfo info2 = manager.login(client);
		assertNotNull(info2);
		assertEquals(info, info2);

		/* 
		// THIS TAKES WAY TO MUCH TIME
		// DoS attack, there should be no handle left...
		try
		{
			Client differentClient = new TestAlwaysNotEqualClient("different");
			for (int i=0; i<HandleConstants.HANDLE_MASK-1; i++)
			{
				System.out.println(i);
				manager.login(differentClient);			
			}
			
			fail();
		}
		catch (NoResourcesException nre)
		{
			new ExceptionIgnorer(nre);
			System.out.println("This is OK: "+nre.getMessage());
		}
		*/
		
		//test administrator login
		Administrator administrator = new TestAdministrator(administratorName);
		info = manager.login(administrator);

		assertNotNull(info);
		assertTrue((info.getHandle() & HandleConstants.ADMINISTRATOR_MASK) == HandleConstants.ADMINISTRATOR_MASK);
		assertEquals(info.getClient(),administrator);
		
		//test duplicate login
		info2 = manager.login(administrator);
		assertNotNull(info2);
		assertEquals(info, info2);

		//test container login
		Container container = new TestContainer(containerName);
		info = manager.login(container);

		assertNotNull(info);
		assertTrue((info.getHandle() & HandleConstants.CONTAINER_MASK) == HandleConstants.CONTAINER_MASK);
		assertEquals(info.getClient(),container);
		
		//test duplicate login
		info2 = manager.login(container);
		assertNotNull(info2);
		assertEquals(info.getHandle(), info2.getHandle());
		
	}

	public void testSequentalContainersLogin() {

		int counter = 0;
		final int SEQUENTAL_LOGINS = 100;

		for (int i = 0; i < SEQUENTAL_LOGINS; i++)
		{
			final String containerName = "Container" + (++counter);
			Container container = new TestContainer(containerName);
			ClientInfo info = manager.login(container);

			assertTrue(containerName + " failed to login.", info != null && info.getHandle() != 0);
		}

	}

	public void testConcurrentContainersLogin() {
		final Object sync = new Object();
		final SynchronizedBoolean done = new SynchronizedBoolean(false);
		final SynchronizedInt counter = new SynchronizedInt(0);
		final SynchronizedInt loginCounter = new SynchronizedInt(0);
		final int CONCURRENT_LOGINS = 100;
		final CyclicBarrier barrier = new CyclicBarrier(CONCURRENT_LOGINS);
		
		class LoginWorker implements Runnable {
			public void run() {

				final String containerName = "Container" + counter.increment();
				Container container = new TestContainer(containerName);
				
				try {
					barrier.barrier();
				} catch (Throwable th) {
					return;
				}

				ClientInfo info = manager.login(container);

				// note that if this fails, tearDown will be called (and manager shutdown)
				assertTrue(containerName + " failed to login.", info != null && info.getHandle() != 0);

				if (loginCounter.increment() == CONCURRENT_LOGINS)
				{
					synchronized (sync) {
						sync.notifyAll();
					}
				}
			}
		}

		synchronized (sync) {

			// spawn threads
			for (int i = 0; i < CONCURRENT_LOGINS; ++i)
				new Thread(new LoginWorker()).start();

			try {
				sync.wait(CONCURRENT_LOGINS * 500);
			} catch (InterruptedException e) {}
		}

		assertTrue("All containers failed to login successfully in time.", loginCounter.get() == CONCURRENT_LOGINS);

	}

	public void testLogout()
	{

		//test invalid
		try {
			manager.logout(0);
			fail();
		}
		catch (NoPermissionException npe)
		{
			new ExceptionIgnorer(npe);
			System.out.println("This is OK: "+npe.getMessage());
		}

		//test invalid
		try {
			manager.logout(Integer.MAX_VALUE);
			fail();
		}
		catch (NoPermissionException npe)
		{
			new ExceptionIgnorer(npe);
			System.out.println("This is OK: "+npe.getMessage());
		}

		//test invalid
		try {
			manager.logout(HandleConstants.CLIENT_MASK);
			fail();
		}
		catch (NoPermissionException npe)
		{
			new ExceptionIgnorer(npe);
			System.out.println("This is OK: "+npe.getMessage());
		}

		//test client logout
		ClientInfo info = manager.login(new TestClient(clientName));
		assertNotNull(info);


		manager.logout(info.getHandle());		

		//test administrator logout
		info = manager.login(new TestAdministrator(administratorName));
		assertNotNull(info);

		manager.logout(info.getHandle());

		//test container logout
		info = manager.login(new TestContainer(containerName));
		assertNotNull(info);

		manager.logout(info.getHandle());				

		
	}
		
	public void testClientInfo()
	{

		//test invalid
		try {
			manager.getClientInfo(0, null, null);
			fail();
		}
		catch (BadParametersException bpe)
		{
			new ExceptionIgnorer(bpe);
			System.out.println("This is OK: "+bpe.getMessage());
		}

		//test invalid
		try {
			manager.getClientInfo(Integer.MAX_VALUE, null, null);
			fail();
		}
		catch (BadParametersException bpe)
		{
			new ExceptionIgnorer(bpe);
			System.out.println("This is OK: "+bpe.getMessage());
		}

		//test invalid
		try {
			manager.getClientInfo(dummyHandle, null, null);
			fail();
		}
		catch (BadParametersException bpe)
		{
			new ExceptionIgnorer(bpe);
			System.out.println("This is OK: "+bpe.getMessage());
		}

		//test invalid
		try {
			manager.getClientInfo(dummyHandle, new int[0], null);		
			fail();
		}
		catch (BadParametersException bpe)
		{
			new ExceptionIgnorer(bpe);
			System.out.println("This is OK: "+bpe.getMessage());
		}

		//test invalid
		try {
			manager.getClientInfo(dummyHandle, new int[0], "non-null");		
			fail();
		}
		catch (NoPermissionException npe)
		{
			new ExceptionIgnorer(npe);
			System.out.println("This is OK: "+npe.getMessage());
		}

		/*
		//test invalid regular expression
		try {
			manager.getClientInfo(dummyHandle, new int[0], ")");		
			fail();
		}
		catch (BadParametersException bpe)
		{
			new ExceptionIgnorer(bpe);
			System.out.println("This is OK: "+bpe.getMessage());
		}
		*/
		
		//test valid
		ClientInfo info = manager.login(new TestClient(clientName));
		int[] handles = {info.getHandle()};
		ClientInfo[] infos = manager.getClientInfo(info.getHandle(),handles,null);
		assertNotNull(infos);
		assertEquals(infos.length,1);
		assertEquals(infos[0],info);

		manager.logout(info.getHandle());

		//test inaccessible
		info = manager.login(new TestClient(clientName));
		handles[0]=info.getHandle();
		ClientInfo anotherInfo = manager.login(new TestClient(anotherName));
		try{
			manager.getClientInfo(anotherInfo.getHandle(),handles,null);	
			fail();			
		} catch (NoPermissionException npe) {
			new ExceptionIgnorer(npe);
			System.out.println("This is OK: "+npe.getMessage());
		}
		try{
			manager.getClientInfo(anotherInfo.getHandle(),new int[0],clientName);
			fail();
		} catch (NoPermissionException npe) {
			new ExceptionIgnorer(npe);
			System.out.println("This is OK: "+npe.getMessage());
		}
		manager.logout(info.getHandle());
		manager.logout(anotherInfo.getHandle());

		//test valid and invalid client info
		info = manager.login(new TestClient(clientName));
		handles = new int[2];
		handles[0] = info.getHandle();
		handles[1] = dummyHandle;
		try {
			infos = manager.getClientInfo(info.getHandle(),handles,null);
			fail();
		} catch (NoPermissionException npe) {
			new ExceptionIgnorer(npe);
			System.out.println("This is OK: "+npe.getMessage());		
		}
		manager.logout(info.getHandle());

		//test invalid and inaccessible client info
		info = manager.login(new TestClient(clientName));
		anotherInfo = manager.login(new TestClient(anotherName));
		handles = new int[2];
		handles[0] = anotherInfo.getHandle();
		handles[1] = dummyHandle;
		try {
			infos = manager.getClientInfo(info.getHandle(),handles,null);
			fail();
		} catch (NoPermissionException npe) {
			new ExceptionIgnorer(npe);
			System.out.println("This is OK: "+npe.getMessage());		
		}
		manager.logout(info.getHandle());
		manager.logout(anotherInfo.getHandle());
		
		//test valid and inaccessible client info
		info = manager.login(new TestClient(clientName));
		anotherInfo = manager.login(new TestClient(anotherName));
		handles = new int[2];
		handles[0]=info.getHandle();
		handles[1]=anotherInfo.getHandle();		
		try {
			infos = manager.getClientInfo(info.getHandle(),handles,null);
			fail();
		} catch (NoPermissionException npe) {
			new ExceptionIgnorer(npe);
			System.out.println("This is OK: "+npe.getMessage());		
		}
		manager.logout(info.getHandle());
		manager.logout(anotherInfo.getHandle());

		//test valid, invalid and inaccessible client info
		info = manager.login(new TestClient(clientName));
		anotherInfo = manager.login(new TestClient(anotherName));
		handles = new int[3];
		handles[0]=info.getHandle();
		handles[1]=anotherInfo.getHandle();
		handles[2]=dummyHandle;
		try {
			infos = manager.getClientInfo(info.getHandle(),handles,null);
			fail();
		} catch (NoPermissionException npe) {
			new ExceptionIgnorer(npe);
			System.out.println("This is OK: "+npe.getMessage());		
		}
		manager.logout(info.getHandle());
		manager.logout(anotherInfo.getHandle());
				
		//test duplicating infos
		info = manager.login(new TestClient(clientName));
		handles = new int[2];
		handles[0]=info.getHandle();
		handles[1]=info.getHandle();
		try {
			infos = manager.getClientInfo(info.getHandle(),handles,null);
			fail();
		} catch (NoPermissionException npe) {
			new ExceptionIgnorer(npe);
			System.out.println("This is OK: "+npe.getMessage());		
		}
		manager.logout(info.getHandle());
		
		//test with INTROSPECTION_MANAGER rights
		info = manager.login(new TestClient(clientName));
		ClientInfo adminInfo = manager.login(new TestAdministrator(administratorName));
		handles = new int[3];
		handles[0]=adminInfo.getHandle();
		handles[1]=info.getHandle();
		handles[2]=dummyHandle;		
		infos = manager.getClientInfo(adminInfo.getHandle(),handles,null);
		assertNotNull(infos);
		assertEquals(infos[0].getHandle(),adminInfo.getHandle());
		assertEquals(infos[1].getHandle(),info.getHandle());
		//assertEquals(infos[2].getHandle(),0);
		assertNull(infos[2]);
		manager.logout(info.getHandle());
		manager.logout(adminInfo.getHandle());
				
		// test wildcard search		
		info = manager.login(new TestClient("client1"));
		assertNotNull(info);
		ClientInfo info2 = manager.login(new TestClient("client2a"));
		assertNotNull(info2);
		ClientInfo info3 = manager.login(new TestClient("client3aa"));
		assertNotNull(info3);
		ClientInfo info4 = manager.login(new TestClient("other4"));
		assertNotNull(info4);
		adminInfo = manager.login(new TestAdministrator("client55"));
		assertNotNull(adminInfo);

		//infos = manager.getClientInfo(adminInfo.getHandle(), new int[0], "client.*");
		infos = manager.getClientInfo(adminInfo.getHandle(), new int[0], "client*");
		assertNotNull(infos);
		assertEquals(4, infos.length);
		assertEquals(info.getHandle(), infos[0].getHandle());
		assertEquals(info2.getHandle(), infos[1].getHandle());
		assertEquals(info3.getHandle(), infos[2].getHandle());
		assertEquals(adminInfo.getHandle(), infos[3].getHandle());
		
		manager.logout(info.getHandle());
		manager.logout(info2.getHandle());
		manager.logout(info3.getHandle());
		manager.logout(info4.getHandle());
		manager.logout(adminInfo.getHandle());

	}

	public void testContainerInfo()
	{
		
		//test invalid
		try {
			manager.getContainerInfo(0, null, null);
			fail();
		}
		catch (BadParametersException bpe)
		{
			new ExceptionIgnorer(bpe);
			System.out.println("This is OK: "+bpe.getMessage());
		}

		//test invalid
		try {
			manager.getContainerInfo(Integer.MAX_VALUE, null, null);
			fail();
		}
		catch (BadParametersException bpe)
		{
			new ExceptionIgnorer(bpe);
			System.out.println("This is OK: "+bpe.getMessage());
		}


		//test invalid
		try {
			manager.getContainerInfo(dummyHandle, null, null);
			fail();
		}
		catch (BadParametersException bpe)
		{
			new ExceptionIgnorer(bpe);
			System.out.println("This is OK: "+bpe.getMessage());
		}

		//test invalid
		try {
			manager.getContainerInfo(dummyHandle, new int[0], null);				
			fail();
		}
		catch (BadParametersException bpe)
		{
			new ExceptionIgnorer(bpe);
			System.out.println("This is OK: "+bpe.getMessage());
		}

		//test invalid
		try {
			manager.getContainerInfo(dummyHandle, new int[0], "non-null");		
			fail();
		}
		catch (NoPermissionException npe)
		{
			new ExceptionIgnorer(npe);
			System.out.println("This is OK: "+npe.getMessage());
		}

		/*
		//test invalid regular expression
		try {
			manager.getContainerInfo(dummyHandle, new int[0], ")");		
			fail();
		}
		catch (BadParametersException bpe)
		{
			new ExceptionIgnorer(bpe);
			System.out.println("This is OK: "+bpe.getMessage());
		}
		*/
		
		//test valid
		ClientInfo info = manager.login(new TestContainer(containerName));
		int[] handles = {info.getHandle()};
		ContainerInfo[] infos = manager.getContainerInfo(info.getHandle(),handles,null);
		assertNotNull(infos);
		assertEquals(infos.length,1);
		assertEquals(infos[0].getHandle(),info.getHandle());

		//test inaccessible
		info = manager.login(new TestContainer(containerName));
		ClientInfo anotherInfo = manager.login(new TestContainer(anotherName));
		handles[0] = anotherInfo.getHandle();
		try{
			infos = manager.getContainerInfo(info.getHandle(),handles,null);	
			fail();			
		} catch (NoPermissionException npe) {
			new ExceptionIgnorer(npe);
			System.out.println("This is OK: "+npe.getMessage());
		}
		try{
			manager.getClientInfo(info.getHandle(),new int[0],anotherName);
			fail();
		} catch (NoPermissionException npe) {
			new ExceptionIgnorer(npe);
			System.out.println("This is OK: "+npe.getMessage());
		}
		manager.logout(info.getHandle());
		manager.logout(anotherInfo.getHandle());
						
		//test with INTROSPECTION_MANAGER rights
		info = manager.login(new TestContainer(containerName));
		ClientInfo adminInfo = manager.login(new TestAdministrator(administratorName));
		handles = new int[3];
		handles[0]=adminInfo.getHandle();
		handles[1]=info.getHandle();
		handles[2]=dummyHandle;
		infos = manager.getContainerInfo(adminInfo.getHandle(),handles,null);
		assertNotNull(infos);
		assertNull(infos[0]);
		assertEquals(infos[1].getHandle(),info.getHandle());
		assertNull(infos[2]);
		manager.logout(info.getHandle());
		manager.logout(adminInfo.getHandle());

		// test wildcard search		
		info = manager.login(new TestContainer("container1"));
		assertNotNull(info);
		ClientInfo info2 = manager.login(new TestContainer("container2a"));
		assertNotNull(info2);
		ClientInfo info3 = manager.login(new TestContainer("container3aa"));
		assertNotNull(info3);
		ClientInfo info4 = manager.login(new TestContainer("other4"));
		assertNotNull(info4);
		adminInfo = manager.login(new TestAdministrator("admin"));
		assertNotNull(adminInfo);

		//infos = manager.getContainerInfo(adminInfo.getHandle(), new int[0], "container.*");
		infos = manager.getContainerInfo(adminInfo.getHandle(), new int[0], "container*");
		assertNotNull(infos);
		assertEquals(3, infos.length);
		assertEquals(info.getHandle(), infos[0].getHandle());
		assertEquals(info2.getHandle(), infos[1].getHandle());
		assertEquals(info3.getHandle(), infos[2].getHandle());
		
		manager.logout(info.getHandle());
		manager.logout(info2.getHandle());
		manager.logout(info3.getHandle());
		manager.logout(info4.getHandle());
		manager.logout(adminInfo.getHandle());
	}
		
	public void testRegisterComponent() {
		
		//test invalid
		try {
			manager.registerComponent(0, null, null, null);
			fail();
		}
		catch (BadParametersException bpe)
		{
			new ExceptionIgnorer(bpe);
			System.out.println("This is OK: "+bpe.getMessage());
		}

		//test invalid
		try {
			manager.registerComponent(dummyHandle, null, type, null);
			fail();
		}
		catch (BadParametersException bpe)
		{
			new ExceptionIgnorer(bpe);
			System.out.println("This is OK: "+bpe.getMessage());
		}

		//test invalid
		try {
			manager.registerComponent(dummyHandle, dummyURI, type, null);
			fail();
		}
		catch (BadParametersException bpe)
		{
			new ExceptionIgnorer(bpe);
			System.out.println("This is OK: "+bpe.getMessage());
		}

		//test invalid
		try {
			manager.registerComponent(dummyHandle, null, null, new TestComponent(cobName));
			fail();
		}
		catch (BadParametersException bpe)
		{
			new ExceptionIgnorer(bpe);
			System.out.println("This is OK: "+bpe.getMessage());
		}
		
		//register with empty curl
		ClientInfo cinfo = manager.login(new TestClient(clientName));
		try {
			manager.registerComponent(cinfo.getHandle(),new URI(""),type,new TestComponent(cobName));
			fail();
		} catch (BadParametersException bpe) {
			new ExceptionIgnorer(bpe);
			System.out.println("This is OK: "+bpe.getMessage());			
		} catch (URISyntaxException e) {
			fail();
		}

		//register with wrong domain
		try {
			manager.registerComponent(cinfo.getHandle(),new URI("curl://other/KIKI"),type,new TestComponent(cobName));
			fail();
		} catch (BadParametersException bpe) {
			new ExceptionIgnorer(bpe);
			System.out.println("This is OK: "+bpe.getMessage());			
		} catch (URISyntaxException e) {
			fail();
		}

		// wrong schema
		try {
			manager.registerComponent(cinfo.getHandle(),new URI("KIKI://other/KIKI"),type,new TestComponent(cobName));
			fail();
		} catch (BadParametersException bpe) {
			new ExceptionIgnorer(bpe);
			System.out.println("This is OK: "+bpe.getMessage());			
		} catch (URISyntaxException e) {
			fail();
		}

		// no path
		try {
			manager.registerComponent(cinfo.getHandle(),new URI("KIKI://other/"),type,new TestComponent(cobName));
			fail();
		} catch (BadParametersException bpe) {
			new ExceptionIgnorer(bpe);
			System.out.println("This is OK: "+bpe.getMessage());			
		} catch (URISyntaxException e) {
			fail();
		}

		//register valid but from other domain
		try {
			manager.registerComponent(cinfo.getHandle(),new URI("curl://other/GIZMO1"),type,new TestComponent(cobName));
			fail();
		} catch (BadParametersException bpe) {
			new ExceptionIgnorer(bpe);
			System.out.println("This is OK: "+bpe.getMessage());			
		} catch (URISyntaxException e) {
			fail();
		}
		
		//register valid
		try {
			int handle = manager.registerComponent(cinfo.getHandle(),new URI("curl:///GIZMO1"),type,new TestComponent(cobName));
			assertTrue(handle != 0);
			assertTrue((handle & HandleConstants.COMPONENT_MASK) == HandleConstants.COMPONENT_MASK);
		} catch (URISyntaxException e) {
			fail();
		}

		try {
			int handle = manager.registerComponent(cinfo.getHandle(),new URI("curl:///GIZMO2"),type,new TestComponent(cobName));
			assertTrue(handle != 0);
			assertTrue((handle & HandleConstants.COMPONENT_MASK) == HandleConstants.COMPONENT_MASK);
		} catch (URISyntaxException e) {
			fail();
		}

		try {
			int handle = manager.registerComponent(cinfo.getHandle(),new URI("GIZMO3"),type,new TestComponent(cobName));
			assertTrue(handle != 0);
			assertTrue((handle & HandleConstants.COMPONENT_MASK) == HandleConstants.COMPONENT_MASK);
		} catch (URISyntaxException e) {
			fail();
		}

		// duplicate
		try {
			TestComponent cob = new TestComponent(cobName);
			int handle1 = manager.registerComponent(cinfo.getHandle(),new URI("curl:///GIZMO4"),type,cob);
			assertTrue(handle1 != 0);
			assertTrue((handle1 & HandleConstants.COMPONENT_MASK) == HandleConstants.COMPONENT_MASK);
			int handle2 = manager.registerComponent(cinfo.getHandle(),new URI("GIZMO4"),type,cob);
			assertTrue(handle2 != 0);
			assertTrue((handle2 & HandleConstants.COMPONENT_MASK) == HandleConstants.COMPONENT_MASK);
			assertEquals(handle1, handle2);
		} catch (URISyntaxException e) {
			fail();
		}

		// duplicate name, different type
		try {
			TestComponent cob = new TestComponent(cobName);
			int handle1 = manager.registerComponent(cinfo.getHandle(),new URI("curl:///GIZMO4"),type,cob);
			assertTrue(handle1 != 0);
			assertTrue((handle1 & HandleConstants.COMPONENT_MASK) == HandleConstants.COMPONENT_MASK);
			manager.registerComponent(cinfo.getHandle(),new URI("GIZMO4"),type+"!",cob);
			fail();
		} catch (NoPermissionException npe) {
			new ExceptionIgnorer(npe);
			System.out.println("This is OK: "+npe.getMessage());
		} catch (URISyntaxException e) {
			fail();
		}

		manager.logout(cinfo.getHandle());
		
	}
	
	public void testUnregisterComponent()
	{

		//test invalid
		try {
			manager.unregisterComponent(0, 0);
			fail();
		}
		catch (NoPermissionException npe)
		{
			new ExceptionIgnorer(npe);
			System.out.println("This is OK: "+npe.getMessage());
		}

		//test invalid
		try {
			manager.unregisterComponent(Integer.MAX_VALUE, 0);
			fail();
		}
		catch (NoPermissionException npe)
		{
			new ExceptionIgnorer(npe);
			System.out.println("This is OK: "+npe.getMessage());
		}

		//test invalid
		try {
			manager.unregisterComponent(dummyHandle, 0);
			fail();
		}
		catch (NoPermissionException npe)
		{
			new ExceptionIgnorer(npe);
			System.out.println("This is OK: "+npe.getMessage());
		}

		//test invalid
		try {
			manager.unregisterComponent(dummyHandle, Integer.MAX_VALUE);
			fail();
		}
		catch (NoPermissionException npe)
		{
			new ExceptionIgnorer(npe);
			System.out.println("This is OK: "+npe.getMessage());
		}
		
		//unregister valid
		ClientInfo info = manager.login(new TestClient(anotherName));
		int handle = manager.registerComponent(info.getHandle(),dummyURI,type,new TestComponent(cobName));		
		manager.unregisterComponent(info.getHandle(),handle);
		
		//duplicate unregistration		
		try {
			manager.unregisterComponent(info.getHandle(), handle);
			fail();
		}
		catch (BadParametersException bpe)
		{
			new ExceptionIgnorer(bpe);
			System.out.println("This is OK: "+bpe.getMessage());
		}

		manager.logout(info.getHandle());		
		
	}

	public void testGetHierarchicalComponent()
	{
		internalTestGetHierarchicalComponent(true);
	}	

	public void testGetHierarchicalComponentConstructCase()
	{
		internalTestGetHierarchicalComponent(false);
	}

	public void internalTestGetHierarchicalComponent(boolean activateOnActivation)
	{
		TestContainer container = new TestContainer("Container");
		Map supportedComponents = new HashMap();

		TestHierarchicalComponent mount2HierCOB = new TestHierarchicalComponent("HierarchicalCOB2", manager, new String[] {"MOUNT3"}, false, activateOnActivation);
		TestHierarchicalComponent mount3HierCOB = new TestHierarchicalComponent("HierarchicalCOB3", manager, new String[] {"MOUNT4"}, false, activateOnActivation);
		Component mount4COB = new TestComponent("MOUNT4");
		
		supportedComponents.put("MOUNT2", mount2HierCOB);
		supportedComponents.put("MOUNT3", mount3HierCOB);
		supportedComponents.put("MOUNT4", mount4COB);
		container.setSupportedComponents(supportedComponents);

		// test case when container is unable to activate startup Component - MOUNT1
		ClientInfo containerInfo = manager.login(container);

		TestAdministrator client = new TestAdministrator(administratorName);
		ClientInfo info = manager.login(client);

		// test ordinary activation
		URI mount2URI;
		try
		{
			mount2URI = new URI("MOUNT2");	
			StatusHolder status = new StatusHolder();
			Component ref = manager.getComponent(info.getHandle(), mount2URI, true, status);
			
			assertEquals(mount2HierCOB, ref);
			assertEquals(ComponentStatus.COMPONENT_ACTIVATED, status.getStatus());
		}
		catch (Exception ex)
		{
			fail();
		}
		
		try { Thread.sleep(STARTUP_COBS_SLEEP_TIME_MS); } catch (InterruptedException ie) {}

		// test activated Components
		// there should be all three Components activated
		ComponentInfo[] infos = manager.getComponentInfo(info.getHandle(), new int[0], "*", "*", true);
		assertEquals(3, infos.length);

		// container logout and login
		manager.logout(containerInfo.getHandle());

		try { Thread.sleep(SLEEP_TIME_MS); } catch (InterruptedException ie) {}

		// test activated Components
		// there should be no Components activated
		infos = manager.getComponentInfo(info.getHandle(), new int[0], "*", "*", true);
		assertEquals(0, infos.length);

		manager.login(container);

		try { Thread.sleep(STARTUP_COBS_SLEEP_TIME_MS); } catch (InterruptedException ie) {}

		// test activated Components
		// there should be all three Components activated
		infos = manager.getComponentInfo(info.getHandle(), new int[0], "*", "*", true);
		assertEquals(3, infos.length);

		// logout client
		manager.logout(info.getHandle());

		try { Thread.sleep(SLEEP_TIME_MS); } catch (InterruptedException ie) {}
		
	}


	public void testGetHierarchicalComponentPassingComponentHandle()
	{
		internalTestGetHierarchicalComponentPassingComponentHandle(true);
	}	

	public void testGetHierarchicalComponentPassingComponentHandleConstructCase()
	{
		internalTestGetHierarchicalComponentPassingComponentHandle(false);
	}

	public void internalTestGetHierarchicalComponentPassingComponentHandle(boolean activateOnActivation)
	{
		TestContainer container = new TestContainer("Container");
		Map supportedComponents = new HashMap();

		TestContainer container2 = new TestContainer("Container2");
		Map supportedComponents2 = new HashMap();

		TestHierarchicalComponent mount2HierCOB = new TestHierarchicalComponent("HierarchicalCOB2", manager, new String[] {"MOUNT3"}, true, activateOnActivation);
		TestHierarchicalComponent mount3HierCOB = new TestHierarchicalComponent("HierarchicalCOB3", manager, new String[] {"MOUNT5"}, true, activateOnActivation);
		Component mount4COB = new TestComponent("MOUNT4");
		
		supportedComponents.put("MOUNT2", mount2HierCOB);
		supportedComponents.put("MOUNT3", mount3HierCOB);
		supportedComponents2.put("MOUNT5", mount4COB);
		container.setSupportedComponents(supportedComponents);
		container2.setSupportedComponents(supportedComponents2);

		// test case when container is unable to activate startup Component - MOUNT1
		ClientInfo containerInfo = manager.login(container);
		ClientInfo containerInfo2 = manager.login(container2);

		TestAdministrator client = new TestAdministrator(administratorName);
		ClientInfo info = manager.login(client);

		// test ordinary activation
		URI mount2URI;
		try
		{
			mount2URI = new URI("MOUNT2");	
			StatusHolder status = new StatusHolder();
			Component ref = manager.getComponent(info.getHandle(), mount2URI, true, status);
			
			assertEquals(mount2HierCOB, ref);
			assertEquals(ComponentStatus.COMPONENT_ACTIVATED, status.getStatus());
		}
		catch (Exception ex)
		{
			fail();
		}
		
		try { Thread.sleep(STARTUP_COBS_SLEEP_TIME_MS); } catch (InterruptedException ie) {}

		// test activated Components
		// there should be all three Components activated
		ComponentInfo[] infos = manager.getComponentInfo(info.getHandle(), new int[0], "*", "*", true);
		assertEquals(3, infos.length);

		// container logout and login
		manager.logout(containerInfo.getHandle());

		try { Thread.sleep(SLEEP_TIME_MS); } catch (InterruptedException ie) {}

		// test activated Components
		// there should be no Components activated on "Container"
		infos = manager.getComponentInfo(info.getHandle(), new int[0], "*", "*", true);
		assertEquals(1, infos.length);

		manager.login(container);

		try { Thread.sleep(STARTUP_COBS_SLEEP_TIME_MS); } catch (InterruptedException ie) {}

		// test activated Components
		// there should be all three Components activated
		infos = manager.getComponentInfo(info.getHandle(), new int[0], "*", "*", true);
		assertEquals(3, infos.length);



		// test ordinary deactivation
		try
		{
			mount2URI = new URI("MOUNT2");	
			int owners = manager.releaseComponent(info.getHandle(), mount2URI);
			assertEquals(0, owners);
		}
		catch (Exception ex)
		{
			fail();
		}

		try { Thread.sleep(STARTUP_COBS_SLEEP_TIME_MS); } catch (InterruptedException ie) {}

		// test activated Components
		// there should be no Components activated (hierarchical deactivation)
		infos = manager.getComponentInfo(info.getHandle(), new int[0], "*", "*", true);
		assertEquals(0, infos.length);

		// test ordinary activation again
		try
		{
			mount2URI = new URI("MOUNT2");	
			StatusHolder status = new StatusHolder();
			Component ref = manager.getComponent(info.getHandle(), mount2URI, true, status);
			
			assertEquals(mount2HierCOB, ref);
			assertEquals(ComponentStatus.COMPONENT_ACTIVATED, status.getStatus());
		}
		catch (Exception ex)
		{
			fail();
		}

		// logout container2
		manager.logout(containerInfo2.getHandle());

		try { Thread.sleep(SLEEP_TIME_MS); } catch (InterruptedException ie) {}

		// logout client
		manager.logout(info.getHandle());

		try { Thread.sleep(SLEEP_TIME_MS); } catch (InterruptedException ie) {}
		
	}

	public void testComponentInfoTopologicalSort()
	{
		boolean activateOnActivation = true;
		
		TestContainer container = new TestContainer("Container");
		Map supportedComponents = new HashMap();

		TestContainer container2 = new TestContainer("Container2");
		Map supportedComponents2 = new HashMap();

		Component mount1COB = new TestComponent("MOUNT1");
		TestHierarchicalComponent mount2HierCOB = new TestHierarchicalComponent("HierarchicalCOB2", manager, new String[] {"MOUNT3"}, true, activateOnActivation);
		TestHierarchicalComponent mount3HierCOB = new TestHierarchicalComponent("HierarchicalCOB3", manager, new String[] {"MOUNT5", "PBEND_B_01"}, true, activateOnActivation);
		Component mount5COB = new TestComponent("MOUNT5");
		TestHierarchicalComponent mount4HierCOB = new TestHierarchicalComponent("HierarchicalCOB4", manager, new String[] {"MOUNT2"}, true, activateOnActivation);
		TestHierarchicalComponent psHierCOB = new TestHierarchicalComponent("HierarchicalPSCOB", manager, new String[] {"MOUNT5"}, true, activateOnActivation);
		
		supportedComponents.put("MOUNT1", mount1COB);
		supportedComponents.put("MOUNT2", mount2HierCOB);
		supportedComponents.put("MOUNT3", mount3HierCOB);
		supportedComponents2.put("MOUNT5", mount5COB);
		supportedComponents.put("MOUNT4", mount4HierCOB);
		supportedComponents.put("PBEND_B_01", psHierCOB);
		container.setSupportedComponents(supportedComponents);
		container2.setSupportedComponents(supportedComponents2);

		// test case when container is unable to activate startup Component - MOUNT1
		ClientInfo containerInfo = manager.login(container);
		ClientInfo containerInfo2 = manager.login(container2);

		TestAdministrator client = new TestAdministrator(administratorName);
		ClientInfo info = manager.login(client);

		// activate hier. components
		URI mount2URI;
		try
		{
			mount2URI = new URI("MOUNT2");	
			StatusHolder status = new StatusHolder();
			Component ref = manager.getComponent(info.getHandle(), mount2URI, true, status);
			
			assertEquals(mount2HierCOB, ref);
			assertEquals(ComponentStatus.COMPONENT_ACTIVATED, status.getStatus());
		}
		catch (Exception ex)
		{
			fail();
		}
		
		// activate orphan component
		URI mount1URI;
		try
		{
			mount1URI = new URI("MOUNT1");	
			StatusHolder status = new StatusHolder();
			Component ref = manager.getComponent(info.getHandle(), mount1URI, true, status);
			
			assertEquals(mount1COB, ref);
			assertEquals(ComponentStatus.COMPONENT_ACTIVATED, status.getStatus());
		}
		catch (Exception ex)
		{
			fail();
		}

		// activate mount4
		URI mount4URI;
		try
		{
			mount4URI = new URI("MOUNT4");	
			StatusHolder status = new StatusHolder();
			Component ref = manager.getComponent(info.getHandle(), mount4URI, true, status);
			
			assertEquals(mount4HierCOB, ref);
			assertEquals(ComponentStatus.COMPONENT_ACTIVATED, status.getStatus());
		}
		catch (Exception ex)
		{
			fail();
		}

		try { Thread.sleep(STARTUP_COBS_SLEEP_TIME_MS); } catch (InterruptedException ie) {}

		// test activated Components
		// there should be all three Components activated
		ComponentInfo[] infos = manager.getComponentInfo(info.getHandle(), new int[0], "*", "*", true);
		assertEquals(6, infos.length);

		// topological sort
		ArrayList solution = new ArrayList(6);
		solution.add(mount4HierCOB);
		solution.add(mount2HierCOB);
		solution.add(mount3HierCOB);
		solution.add(psHierCOB);
		solution.add(mount5COB);
		solution.add(mount1COB);
			
		List list = ComponentInfoTopologicalSort.sort(manager.getComponents());
		assertEquals(solution.size(), list.size());
		int len = solution.size();
		for (int i = 0; i < len; i++)
			assertEquals(solution.get(i), ((ComponentInfo)list.get(i)).getComponent());
		
	}

	public void testManagerShutdownWithComponentDestruction()
	{
		boolean activateOnActivation = true;
		
		TestContainer container = new TestContainer("Container");
		Map supportedComponents = new HashMap();

		TestContainer container2 = new TestContainer("Container2");
		Map supportedComponents2 = new HashMap();

		TestComponent mount1COB = new TestComponent("MOUNT1");
		TestHierarchicalComponent mount2HierCOB = new TestHierarchicalComponent("HierarchicalCOB2", manager, new String[] {"MOUNT3"}, true, activateOnActivation);
		TestHierarchicalComponent mount3HierCOB = new TestHierarchicalComponent("HierarchicalCOB3", manager, new String[] {"MOUNT5", "PBEND_B_01"}, true, activateOnActivation);
		TestComponent mount5COB = new TestComponent("MOUNT5");
		TestHierarchicalComponent mount4HierCOB = new TestHierarchicalComponent("HierarchicalCOB4", manager, new String[] {"MOUNT2"}, true, activateOnActivation);
		TestHierarchicalComponent psHierCOB = new TestHierarchicalComponent("HierarchicalPSCOB", manager, new String[] {"MOUNT5"}, true, activateOnActivation);
		
		supportedComponents.put("MOUNT1", mount1COB);
		supportedComponents.put("MOUNT2", mount2HierCOB);
		supportedComponents.put("MOUNT3", mount3HierCOB);
		supportedComponents2.put("MOUNT5", mount5COB);
		supportedComponents.put("MOUNT4", mount4HierCOB);
		supportedComponents.put("PBEND_B_01", psHierCOB);
		container.setSupportedComponents(supportedComponents);
		container2.setSupportedComponents(supportedComponents2);

		ClientInfo containerInfo = manager.login(container);
		ClientInfo containerInfo2 = manager.login(container2);

		TestAdministrator client = new TestAdministrator(administratorName);
		ClientInfo info = manager.login(client);

		try { Thread.sleep(STARTUP_COBS_SLEEP_TIME_MS); } catch (InterruptedException ie) {}

		// activate hier. components
		URI mount2URI;
		try
		{
			mount2URI = new URI("MOUNT2");	
			StatusHolder status = new StatusHolder();
			Component ref = manager.getComponent(info.getHandle(), mount2URI, true, status);
			
			assertEquals(mount2HierCOB, ref);
			assertEquals(ComponentStatus.COMPONENT_ACTIVATED, status.getStatus());
		}
		catch (Exception ex)
		{
			fail();
		}
		
		// activate orphan component
		URI mount1URI;
		try
		{
			mount1URI = new URI("MOUNT1");	
			StatusHolder status = new StatusHolder();
			Component ref = manager.getComponent(info.getHandle(), mount1URI, true, status);
			
			assertEquals(mount1COB, ref);
			assertEquals(ComponentStatus.COMPONENT_ACTIVATED, status.getStatus());
		}
		catch (Exception ex)
		{
			fail();
		}

		// activate mount4
		URI mount4URI;
		try
		{
			mount4URI = new URI("MOUNT4");	
			StatusHolder status = new StatusHolder();
			Component ref = manager.getComponent(info.getHandle(), mount4URI, true, status);
			
			assertEquals(mount4HierCOB, ref);
			assertEquals(ComponentStatus.COMPONENT_ACTIVATED, status.getStatus());
		}
		catch (Exception ex)
		{
			fail();
		}

		try { Thread.sleep(STARTUP_COBS_SLEEP_TIME_MS); } catch (InterruptedException ie) {}

		// test activated Components
		// there should be all three Components activated
		ComponentInfo[] infos = manager.getComponentInfo(info.getHandle(), new int[0], "*", "*", true);
		assertEquals(6, infos.length);

		// check container shutdown order
		int[] containerSolution = new int[] {
				mount4HierCOB.getHandle(),
				mount2HierCOB.getHandle(),
				mount3HierCOB.getHandle(),
				psHierCOB.getHandle(),
				mount1COB.getHandle()
		};
		
		int [] containerOrder = container.get_component_shutdown_order();
		assertNotNull(containerOrder);
		assertEquals(containerSolution.length, containerOrder.length);
		for (int i = 0; i < containerSolution.length; i++)
			assertEquals(containerSolution[i], containerOrder[i]);
		
		
		int [] container2Order = container2.get_component_shutdown_order();
		/*
		int[] container2Solution = new int[] {mount5COB.getHandle()}; 
		assertNotNull(container2Order);
		assertEquals(container2Solution.length, container2Order.length);
		for (int i = 0; i < container2Solution.length; i++)
			assertEquals(container2Solution[i], container2Order[i]);
		*/
		// optimization, no notification if sequence size is not less than 1
		assertNull(container2Order);
		
		// check shutdown
		try
		{
			manager.shutdown(manager.getHandle(), 1);

			try { Thread.sleep(STARTUP_COBS_SLEEP_TIME_MS); } catch (InterruptedException ie) {}

			assertEquals(0, container.getActivatedComponents().size());
			assertEquals(0, container2.getActivatedComponents().size());
		}
		finally
		{
			// tearDown should not shutdown
			manager = null;
		}
	}

	public void testGetCyclicHierachicalComponent() 
	{
		testGetCyclicHierachicalComponent(true);
	}
	
	/*
	This test was disabled, since construct() is not yet implemented as it should be,
	now it activation (named) lock is aquired also when construct() method is called!
	 
	public void testGetCyclicHierachicalComponentConstructCase()
	{
		// activation of subcomponents is requested in construct() method 
		testGetCyclicHierachicalComponent(false);
	}
	*/
	
	private void testGetCyclicHierachicalComponent(boolean constructCase)
	{

		TestContainer container = new TestContainer("Container");
		Map supportedComponents = new HashMap();

		// MOUNT2 -> MOUNT2 cycle
		TestHierarchicalComponent mount2HierCOB = new TestHierarchicalComponent("CyclicHierarchical", manager, new String[] {"MOUNT2"}, true, constructCase);
		supportedComponents.put("MOUNT2", mount2HierCOB);

		// MOUNT3 -> MOUNT5 -> PBEND_B_01 -> MOUNT3 cycle
		TestHierarchicalComponent mount3HierCOB = new TestHierarchicalComponent("MOUNT3", manager, new String[] {"MOUNT4"}, true, constructCase);
		supportedComponents.put("MOUNT3", mount3HierCOB);
		
		TestHierarchicalComponent mount4HierCOB = new TestHierarchicalComponent("MOUNT4", manager, new String[] {"PBEND_B_01"}, true, constructCase);
		supportedComponents.put("MOUNT4", mount4HierCOB);

		TestHierarchicalComponent pbendHierCOB = new TestHierarchicalComponent("PBEND_B_01", manager, new String[] {"MOUNT3"}, true, constructCase);
		supportedComponents.put("PBEND_B_01", pbendHierCOB);

		container.setSupportedComponents(supportedComponents);

		TestAdministrator client = new TestAdministrator(administratorName);
		ClientInfo info = manager.login(client);

		// test case when container is unable to activate startup Component - MOUNT1
		ClientInfo containerInfo = manager.login(container);

		long startTime = System.currentTimeMillis();
		
		// this will cause cyclic depedency...
		try
		{
			URI mount2URI = new URI("MOUNT2");	
			StatusHolder status = new StatusHolder();
			Component ref = manager.getComponent(info.getHandle(), mount2URI, true, status);
			
			assertEquals(null, ref);
			assertEquals(ComponentStatus.COMPONENT_NOT_ACTIVATED, status.getStatus());
		}
		catch (Exception ex)
		{
			fail();
		}
		
		long stopTime = System.currentTimeMillis();
		
		// cyclic dependency should be detected, not deadlock detected
		if (stopTime - startTime > 30000)
			fail("Cyclic dependency detection is too slow.");

	
	
	
	
		startTime = System.currentTimeMillis();
		
		// this will cause cyclic depedency...
		try
		{
			URI mount3URI = new URI("MOUNT3");	
			StatusHolder status = new StatusHolder();
			Component ref = manager.getComponent(info.getHandle(), mount3URI, true, status);
			
			assertEquals(null, ref);
			assertEquals(ComponentStatus.COMPONENT_NOT_ACTIVATED, status.getStatus());
		}
		catch (Exception ex)
		{
			fail();
		}
		
		stopTime = System.currentTimeMillis();
		
		// cyclic dependency should be detected, not deadlock detected
		if (stopTime - startTime > 30000)
			fail("Cyclic dependency detection is too slow.");
	
	}

	// if one component in a cycle is preactivated, that this is allowed
	public void testGetCyclicHierachicalComponentAllowWithPreactivated(/*boolean constructCase*/)
	{
		boolean constructCase = false;

		TestContainer container = new TestContainer("Container");
		Map supportedComponents = new HashMap();

		// MOUNT3 -> (last will request MOUNT4)
		TestHierarchicalComponent mount3HierCOB = new TestHierarchicalComponent("MOUNT3", manager, new String[] {}, true, constructCase);
		supportedComponents.put("MOUNT3", mount3HierCOB);
		
		// MOUNT4 -> PBEND_B_01 -> MOUNT3 cycle
		TestHierarchicalComponent mount4HierCOB = new TestHierarchicalComponent("MOUNT4", manager, new String[] {"PBEND_B_01"}, true, constructCase);
		supportedComponents.put("MOUNT4", mount4HierCOB);

		TestHierarchicalComponent pbendHierCOB = new TestHierarchicalComponent("PBEND_B_01", manager, new String[] {"MOUNT3"}, true, constructCase);
		supportedComponents.put("PBEND_B_01", pbendHierCOB);

		container.setSupportedComponents(supportedComponents);

		TestAdministrator client = new TestAdministrator(administratorName);
		ClientInfo info = manager.login(client);

		// test case when container is unable to activate startup Component - MOUNT1
		ClientInfo containerInfo = manager.login(container);

		// activate MOUNT3
		try
		{
			URI mount3URI = new URI("MOUNT3");	
			StatusHolder status = new StatusHolder();
			Component ref = manager.getComponent(info.getHandle(), mount3URI, true, status);
			
			assertEquals(mount3HierCOB, ref);
			assertEquals(ComponentStatus.COMPONENT_ACTIVATED, status.getStatus());
		}
		catch (Exception ex)
		{
			fail();
		}
		
		// not MOUNT3 will require MOUNT5 (this will make a cycle with preactivated MOUNT3)
		// this should be allowed
		try
		{
			URI mount4URI = new URI("MOUNT4");	
			StatusHolder status = new StatusHolder();
			Component ref = manager.getComponent(mount3HierCOB.getHandle(), mount4URI, true, status);
			
			assertEquals(mount4HierCOB, ref);
			assertEquals(ComponentStatus.COMPONENT_ACTIVATED, status.getStatus());
		}
		catch (Exception ex)
		{
			fail();
		}
		
		// test activated Components
		// there should be all three Components activated
		ComponentInfo[] infos = manager.getComponentInfo(info.getHandle(), new int[0], "*", "*", true);
		assertEquals(3, infos.length);
	}

	public void testStartupComponents()
	{
		
		TestContainer container = new TestContainer("Container");
		Map supportedComponents = new HashMap();

		TestComponent mount1COB = new TestComponent("MOUNT1");
		
		supportedComponents.put("MOUNT1", mount1COB);
		container.setSupportedComponents(supportedComponents);

		TestAdministrator client = new TestAdministrator(administratorName);
		ClientInfo info = manager.login(client);

		// test case when container is unable to activate startup Component - MOUNT1
		ClientInfo containerInfo = manager.login(container);

		try { Thread.sleep(STARTUP_COBS_SLEEP_TIME_MS); } catch (InterruptedException ie) {}

		// there should be only no Components activated
		ComponentInfo[] infos = manager.getComponentInfo(info.getHandle(), new int[0], "*", "*", true);
		assertEquals(1, infos.length);

		assertTrue("MOUNT1".equals(infos[0].getName()));
		
		// manager and client
		assertEquals(1, infos[0].getClients().size());
		assertTrue(infos[0].getClients().contains(HandleConstants.MANAGER_MASK));

		// container logout and login
		manager.logout(containerInfo.getHandle());

		try { Thread.sleep(SLEEP_TIME_MS); } catch (InterruptedException ie) {}

		infos = manager.getComponentInfo(info.getHandle(), new int[0], "*", "*", true);
		assertEquals(0, infos.length);

		manager.login(container);

		try { Thread.sleep(STARTUP_COBS_SLEEP_TIME_MS); } catch (InterruptedException ie) {}

		// there should be only no Components activated
		infos = manager.getComponentInfo(info.getHandle(), new int[0], "*", "*", true);
		assertEquals(1, infos.length);

		assertTrue("MOUNT1".equals(infos[0].getName()));
		
		// manager 
		assertEquals(1, infos[0].getClients().size());
		assertTrue(infos[0].getClients().contains(HandleConstants.MANAGER_MASK));


		manager.logout(info.getHandle());		

		try { Thread.sleep(SLEEP_TIME_MS); } catch (InterruptedException ie) {}
	}



	public void testGetComponent()
	{
		
		try
		{
			manager.getComponent(0, null, false, null);
			fail();
		}
		catch (BadParametersException bpe)
		{
			new ExceptionIgnorer(bpe);
			System.out.println("This is OK: "+bpe.getMessage());
		}
		
		try
		{
			manager.getComponent(Integer.MAX_VALUE, null, false, null);
			fail();
		}
		catch (BadParametersException bpe)
		{
			new ExceptionIgnorer(bpe);
			System.out.println("This is OK: "+bpe.getMessage());
		}

		try
		{
			StatusHolder status = null;
			manager.getComponent(dummyHandle, dummyURI, false, status);
			fail();
		}
		catch (BadParametersException bpe)
		{
			new ExceptionIgnorer(bpe);
			System.out.println("This is OK: "+bpe.getMessage());
		}
		
		try
		{
			StatusHolder status = new StatusHolder();
			manager.getComponent(dummyHandle, null, false, status);
			fail();
		}
		catch (BadParametersException bpe)
		{
			new ExceptionIgnorer(bpe);
			System.out.println("This is OK: "+bpe.getMessage());
		}


		TestAdministrator client = new TestAdministrator(administratorName);
		ClientInfo info = manager.login(client);
		
		assertTrue(info.getHandle() != 0);
		
		// get unexistant
		try
		{
			StatusHolder status = new StatusHolder();
			Component ref = manager.getComponent(info.getHandle(), dummyURI, true, status);
			
			assertEquals(null, ref);
			assertEquals(ComponentStatus.COMPONENT_NONEXISTANT, status.getStatus());
		}
		catch (Exception ex)
		{
			fail();
		}
		
		// test no activation 
		URI mount = null;
		try
		{
			mount = new URI("MOUNT1");
			
			StatusHolder status = new StatusHolder();
			Component ref = manager.getComponent(info.getHandle(), mount, false, status);
			
			assertEquals(null, ref);
			assertEquals(ComponentStatus.COMPONENT_NOT_ACTIVATED, status.getStatus());
		}
		catch (Exception ex)
		{
			fail();
		}

		// test activation w/o container
		try
		{
			StatusHolder status = new StatusHolder();
			Component ref = manager.getComponent(info.getHandle(), mount, true, status);
			
			assertEquals(null, ref);
			assertEquals(ComponentStatus.COMPONENT_NOT_ACTIVATED, status.getStatus());
		}
		catch (Exception ex)
		{
			fail();
		}
		
		// there should be only no Components activated
		ComponentInfo[] infos = manager.getComponentInfo(info.getHandle(), new int[0], "*", "*", true);
		assertEquals(0, infos.length);

		TestContainer container = new TestContainer("Container");
		Map supportedComponents = new HashMap();
		Component mount1COB = new TestComponent("MOUNT1");
		supportedComponents.put("MOUNT1", mount1COB);
		supportedComponents.put("MOUNT2", null);
		supportedComponents.put("MOUNT3", new TestComponent("MOUNT3", true, false));
		Component mount4COB = new TestComponent("MOUNT4", false, true);
		supportedComponents.put("MOUNT4", mount4COB);
		container.setSupportedComponents(supportedComponents);

		ClientInfo containerInfo = manager.login(container);

		// here also parallel activation will be tested (autostart and activation bellow)

		// test ordinary activation
		try
		{
			StatusHolder status = new StatusHolder();
			Component ref = manager.getComponent(info.getHandle(), mount, true, status);
			
			assertEquals(mount1COB, ref);
			assertEquals(ComponentStatus.COMPONENT_ACTIVATED, status.getStatus());
		}
		catch (Exception ex)
		{
			fail();
		}

		// test failed activation
		URI mount2 = null;
		try
		{
			mount2 = new URI("MOUNT2");
			StatusHolder status = new StatusHolder();
			Component ref = manager.getComponent(info.getHandle(), mount2, true, status);
			
			assertEquals(null, ref);
			assertEquals(ComponentStatus.COMPONENT_NOT_ACTIVATED, status.getStatus());

			// client should be owner of only one component
			ClientInfo[] ci = manager.getClientInfo(info.getHandle(), new int[] { info.getHandle() }, null);
			assertNotNull(ci);
			assertEquals(1, ci.length);
			// only mount 1
			assertEquals(1, ci[0].getComponents().size());
		}
		catch (Exception ex)
		{
			fail();
		}

		// test failed activation (construct failure)
		URI mount3 = null;
		try
		{
			mount3 = new URI("MOUNT3");
			StatusHolder status = new StatusHolder();
			Component ref = manager.getComponent(info.getHandle(), mount3, true, status);
			
			assertEquals(null, ref);
			assertEquals(ComponentStatus.COMPONENT_NOT_ACTIVATED, status.getStatus());
		}
		catch (Exception ex)
		{
			fail();
		}

		// test no activation w/ activated component
		try
		{
			StatusHolder status = new StatusHolder();
			Component ref = manager.getComponent(info.getHandle(), mount, false, status);
			
			assertTrue(ref != null);
			assertEquals(ComponentStatus.COMPONENT_ACTIVATED, status.getStatus());
		}
		catch (Exception ex)
		{
			fail();
		}

		// test failed destruction
		// test will be affected in client logout
		URI mount4 = null;
		try
		{
			mount4 = new URI("MOUNT4");
			StatusHolder status = new StatusHolder();
			Component ref = manager.getComponent(info.getHandle(), mount4, true, status);
			
			assertEquals(mount4COB, ref);
			assertEquals(ComponentStatus.COMPONENT_ACTIVATED, status.getStatus());
		}
		catch (Exception ex)
		{
			fail();
		}

		try { Thread.sleep(STARTUP_COBS_SLEEP_TIME_MS); } catch (InterruptedException ie) {}

		// test activated Components
		// there should be only two Components activated (MOUNT1 and MOUNT4)
		infos = manager.getComponentInfo(info.getHandle(), new int[0], "*", "*", true);

		assertEquals(2, infos.length);

		assertTrue(mount.toString().equals(infos[0].getName()));
		// manager and client
		assertEquals(2, infos[0].getClients().size());
		assertTrue(infos[0].getClients().contains(info.getHandle()));
		assertTrue(infos[0].getClients().contains(HandleConstants.MANAGER_MASK));

		assertTrue(mount4.toString().equals(infos[1].getName()));
		// client
		assertEquals(1, infos[1].getClients().size());
		assertTrue(infos[1].getClients().contains(info.getHandle()));

		// test unavailable and startup
		manager.logout(containerInfo.getHandle());
		containerInfo = manager.login(container);

		try { Thread.sleep(STARTUP_COBS_SLEEP_TIME_MS); } catch (InterruptedException ie) {}

		// test activated Components after activation
		// there should be only two Components activated (MOUNT1 and MOUNT4)
		infos = manager.getComponentInfo(info.getHandle(), new int[0], "*", "*", true);

		assertEquals(2, infos.length);

		assertTrue(mount.toString().equals(infos[0].getName()));
		// manager and client
		assertEquals(2, infos[0].getClients().size());
		assertTrue(infos[0].getClients().contains(info.getHandle()));
		assertTrue(infos[0].getClients().contains(HandleConstants.MANAGER_MASK));

		assertTrue(mount4.toString().equals(infos[1].getName()));
		// client
		assertEquals(1, infos[1].getClients().size());
		assertTrue(infos[1].getClients().contains(info.getHandle()));

		// client logout
		manager.logout(info.getHandle());

		client = new TestAdministrator(administratorName);
		info = manager.login(client);
		assertTrue(info.getHandle() != 0);

		try { Thread.sleep(SLEEP_TIME_MS); } catch (InterruptedException ie) {}

		// there should be only one component activated (MOUNT1)
		infos = manager.getComponentInfo(info.getHandle(), new int[0], "*", "*", true);
		assertEquals(1, infos.length);

		try { Thread.sleep(SLEEP_TIME_MS); } catch (InterruptedException ie) {}

		manager.logout(containerInfo.getHandle());

		try { Thread.sleep(SLEEP_TIME_MS); } catch (InterruptedException ie) {}


		// there should be only no components activated
		infos = manager.getComponentInfo(info.getHandle(), new int[0], "*", "*", true);
		assertEquals(0, infos.length);

		// client logout
		manager.logout(info.getHandle());
		
	}

	public void testGetComponents()
	{	

		try
		{
			manager.getComponents(0, null, false, null);
			fail();
		}
		catch (BadParametersException bpe)
		{
			new ExceptionIgnorer(bpe);
			System.out.println("This is OK: "+bpe.getMessage());
		}

		try
		{
			manager.getComponents(Integer.MAX_VALUE, null, false, null);
			fail();
		}
		catch (BadParametersException bpe)
		{
			new ExceptionIgnorer(bpe);
			System.out.println("This is OK: "+bpe.getMessage());
		}
	
		try
		{
			StatusSeqHolder statusSeq = null;
			manager.getComponents(dummyHandle, new URI[0], false, statusSeq);
			fail();
		}
		catch (BadParametersException bpe)
		{
			new ExceptionIgnorer(bpe);
			System.out.println("This is OK: "+bpe.getMessage());
		}
			
		try
		{
			StatusSeqHolder statusSeq = new StatusSeqHolder();
			manager.getComponents(dummyHandle, new URI[] { null }, false, statusSeq);
			fail();
		}
		catch (NoPermissionException npe)
		{
			new ExceptionIgnorer(npe);
			System.out.println("This is OK: "+npe.getMessage());
		}

		try
		{
			StatusSeqHolder statusSeq = new StatusSeqHolder();
			manager.getComponents(dummyHandle, new URI[] { dummyURI, null }, false, statusSeq);
			fail();
		}
		catch (NoPermissionException npe)
		{
			new ExceptionIgnorer(npe);
			System.out.println("This is OK: "+npe.getMessage());
		}

		try
		{
			StatusSeqHolder statusSeq = new StatusSeqHolder();
			manager.getComponents(dummyHandle, new URI[] { dummyURI, null, dummyURI }, false, statusSeq);
			fail();
		}
		catch (NoPermissionException npe)
		{
			new ExceptionIgnorer(npe);
			System.out.println("This is OK: "+npe.getMessage());
		}
	
		try
		{
			StatusSeqHolder statusSeq = null;
			URI[] seqURIs = new URI[] { dummyURI, dummyURI};
			manager.getComponents(dummyHandle, seqURIs, false, statusSeq);
			fail();
		}
		catch (BadParametersException bpe)
		{
			new ExceptionIgnorer(bpe);
			System.out.println("This is OK: "+bpe.getMessage());
		}
	
		try
		{
			StatusSeqHolder statusSeq = new StatusSeqHolder();
			URI[] seqURIs = new URI[] { dummyURI, dummyURI };
			manager.getComponents(dummyHandle, seqURIs, false, statusSeq);
			fail();
		}
		catch (NoPermissionException npe)
		{
			new ExceptionIgnorer(npe);
			System.out.println("This is OK: "+npe.getMessage());
		}
		
		try
		{
			StatusSeqHolder statusSeq = new StatusSeqHolder();
			manager.getComponents(dummyHandle, null, false, statusSeq);
			fail();
		}
		catch (BadParametersException bpe)
		{
			new ExceptionIgnorer(bpe);
			System.out.println("This is OK: "+bpe.getMessage());
		}
	
	}
	
	/**
	 * Test getDefaultComponent.
	 */
	public void testGetDefaultComponent()
	{
		try
		{
			manager.getDefaultComponent(0, null);
			fail();
		}
		catch (BadParametersException bpe)
		{
			new ExceptionIgnorer(bpe);
			System.out.println("This is OK: "+bpe.getMessage());
		}

		try
		{
			manager.getDefaultComponent(Integer.MAX_VALUE, null);
			fail();
		}
		catch (BadParametersException bpe)
		{
			new ExceptionIgnorer(bpe);
			System.out.println("This is OK: "+bpe.getMessage());
		}

		try
		{
			manager.getDefaultComponent(dummyHandle, "dummyType");
			fail();
		}
		catch (NoPermissionException npe)
		{
			new ExceptionIgnorer(npe);
			System.out.println("This is OK: "+npe.getMessage());
		}


		TestClient client = new TestClient(clientName);
		ClientInfo info = manager.login(client);
	
		assertTrue(info.getHandle() != 0);
	
		try
		{
			manager.getDefaultComponent(info.getHandle(), null);
			fail();
		}
		catch (BadParametersException bpe)
		{
			new ExceptionIgnorer(bpe);
			System.out.println("This is OK: "+bpe.getMessage());
		}

		try
		{
			manager.getDefaultComponent(info.getHandle(), "invalid");
			fail();
		}
		catch (NoDefaultComponentException ndce)
		{
			new ExceptionIgnorer(ndce);
			System.out.println("This is OK: "+ndce.getMessage());
		}

		TestContainer container = new TestContainer("Container");
		Map supportedComponents = new HashMap();
		Component mount3COB = new TestComponent("MOUNT3");
		supportedComponents.put("MOUNT3", mount3COB);
		container.setSupportedComponents(supportedComponents);

		/*ClientInfo containerInfo = */manager.login(container);

		try
		{
			ComponentInfo componentInfo = manager.getDefaultComponent(info.getHandle(), "IDL:alma/MOUNT_ACS/Mount:1.0");
			
			assertTrue(componentInfo != null);
			assertEquals(componentInfo.getComponent(), mount3COB);
		}
		catch (NoDefaultComponentException ndce)
		{
			fail();
		}

	}

	/**
	 * Test getDynamicComponent.
	 */
	public void testGetDynamicComponent()
	{
		try
		{
			manager.getDynamicComponent(0, null, false);
			fail();
		}
		catch (BadParametersException bpe)
		{
			new ExceptionIgnorer(bpe);
			System.out.println("This is OK: "+bpe.getMessage());
		}

		final ComponentSpec allAsterixCompSpec = new ComponentSpec(ComponentSpec.COMPSPEC_ANY,
																   ComponentSpec.COMPSPEC_ANY,
																   ComponentSpec.COMPSPEC_ANY, 
																   ComponentSpec.COMPSPEC_ANY);

		try
		{
			manager.getDynamicComponent(Integer.MAX_VALUE, allAsterixCompSpec, true);
			fail();
		}
		catch (NoPermissionException npe)
		{
			new ExceptionIgnorer(npe);
			System.out.println("This is OK: "+npe.getMessage());
		}

		try
		{
			manager.getDynamicComponent(dummyHandle, allAsterixCompSpec, false);
			fail();
		}
		catch (NoPermissionException npe)
		{
			new ExceptionIgnorer(npe);
			System.out.println("This is OK: "+npe.getMessage());
		}


		TestClient client = new TestClient(clientName);
		ClientInfo info = manager.login(client);
	
		assertTrue(info.getHandle() != 0);
	
		try
		{
			manager.getDynamicComponent(info.getHandle(), null, true);
			fail();
		}
		catch (BadParametersException bpe)
		{
			new ExceptionIgnorer(bpe);
			System.out.println("This is OK: "+bpe.getMessage());
		}

		try
		{
			manager.getDynamicComponent(info.getHandle(), new ComponentSpec(null, null, null, null), false);
			fail();
		}
		catch (BadParametersException ndce)
		{
			new ExceptionIgnorer(ndce);
			System.out.println("This is OK: "+ndce.getMessage());
		}

		try
		{
			manager.getDynamicComponent(info.getHandle(), allAsterixCompSpec, false);
			fail();
		}
		catch (IncompleteComponentSpecException icse)
		{
			new ExceptionIgnorer(icse);
			System.out.println("This is OK: "+icse.getMessage());
		}

		final ComponentSpec nameTypeIncomplete = new ComponentSpec(ComponentSpec.COMPSPEC_ANY,
																   ComponentSpec.COMPSPEC_ANY,
																   "PowerSupply", 
																   "IDL:acsexmpl/PS/PowerSupply:1.0");

		try
		{
			manager.getDynamicComponent(info.getHandle(), nameTypeIncomplete, false);
			fail();
		}
		catch (IncompleteComponentSpecException icse)
		{
			new ExceptionIgnorer(icse);
			System.out.println("This is OK: "+icse.getMessage());
		}

		// decoy container
		TestContainer container = new TestContainer("Container");
		Map supportedComponents = new HashMap();
		TestComponent mount1COB = new TestComponent("MOUNT1");
		supportedComponents.put("MOUNT1", mount1COB);
		container.setSupportedComponents(supportedComponents);

		/*ClientInfo containerInfo =*/ manager.login(container);

		
		TestContainer dynContainer = new TestDynamicContainer("DynContainer");

		ClientInfo dynContainerInfo = manager.login(dynContainer);

		// wait containers to startup
		try { Thread.sleep(STARTUP_COBS_SLEEP_TIME_MS); } catch (InterruptedException ie) {}

		// all dynamic case w/o container logged in
		try
		{
			ComponentInfo componentInfo = manager.getDynamicComponent(info.getHandle(),
												new ComponentSpec("dynComponent", "java.lang.Object",
																  "java.lang.Object", "invalidContainer"), true);
			assertEquals(null, componentInfo);
		}
		catch (Exception ex)
		{
			fail();
		}

		// all dynamic case
		try
		{
			ComponentInfo componentInfo = manager.getDynamicComponent(info.getHandle(),
												new ComponentSpec("dynComponent", "java.lang.Object",
																  "java.lang.Object", "DynContainer"), true);
			assertTrue(componentInfo != null);
			assertTrue(componentInfo.getName().equals("dynComponent"));
			assertEquals(dynContainerInfo.getHandle(), componentInfo.getContainer());
		}
		catch (Exception ex)
		{
			fail();
		}


		ClientInfo info2 = manager.login(new TestClient("TestClient2"));

		// obtain and release dynamic component in a normal way
		try
		{
			URI dynURI = new URI("dynComponent");

			// obtain
			StatusHolder status = new StatusHolder();
			Component component = manager.getComponent(info2.getHandle(), dynURI, true, status);
			
			assertNotNull(component);
			assertEquals(ComponentStatus.COMPONENT_ACTIVATED, status.getStatus());
			
			
			// release
			int owners = manager.releaseComponent(info2.getHandle(), dynURI);
			
			assertEquals(1, owners);
		}
		catch (Exception ex)
		{
			fail();
		}

		// override container case
		try
		{
			ComponentInfo componentInfo = manager.getDynamicComponent(info.getHandle(),
												new ComponentSpec("MOUNT2", ComponentSpec.COMPSPEC_ANY,
																  ComponentSpec.COMPSPEC_ANY, "DynContainer"), true);
			assertTrue(componentInfo != null);
			assertTrue(componentInfo.getName().equals("MOUNT2"));
			assertEquals(dynContainerInfo.getHandle(), componentInfo.getContainer());
		}
		catch (Exception ex)
		{
			fail();
		}

		// override all other fields case but MOUNT2 is already activated
		try
		{
			manager.getDynamicComponent(info.getHandle(),
										new ComponentSpec("MOUNT2", "java.lang.Object",
														  "java.lang.Object", "DynContainer"), true);
			fail();
		}
		catch (ComponentSpecIncompatibleWithActiveComponentException ciwace)
		{
			new ExceptionIgnorer(ciwace);
			System.out.println("This is OK: "+ciwace.getMessage());
		}

		// ordinary activation case but MOUNT2 is already activated
		URI mount2 = null;
		try
		{
			mount2 = CURLHelper.createURI("MOUNT2");
			StatusHolder status = new StatusHolder();
			Component component = manager.getComponent(info.getHandle(), mount2, true, status);
			
			assertNotNull(null, component);
			assertEquals(ComponentStatus.COMPONENT_ACTIVATED, status.getStatus());
		}
		catch (Exception ex)
		{
			fail();
		}
		
		// default component test, should be overriden MOUNT2
		try
		{
			ComponentInfo componentInfo = manager.getDefaultComponent(info.getHandle(), "IDL:alma/MOUNT_ACS/Mount:1.0");

			assertTrue(componentInfo != null);
			assertTrue(componentInfo.getName().equals("MOUNT2"));
			assertEquals(dynContainerInfo.getHandle(), componentInfo.getContainer());
		}
		catch (Exception ex)
		{
			fail();
		}

		// release mount2
		manager.releaseComponent(info.getHandle(), mount2);
		
		// default component test, should still be overriden MOUNT2
		try
		{
			ComponentInfo componentInfo = manager.getDefaultComponent(info.getHandle(), "IDL:alma/MOUNT_ACS/Mount:1.0");

			assertTrue(componentInfo != null);
			assertTrue(componentInfo.getName().equals("MOUNT2"));
			assertEquals(dynContainerInfo.getHandle(), componentInfo.getContainer());
		}
		catch (Exception ex)
		{
			fail();
		}
		

		// release mount2
		manager.releaseComponent(info.getHandle(), mount2);


		// override test case but MOUNT1 is already activated (startup component)
		// type override
		try
		{
			manager.getDynamicComponent(info.getHandle(),
										new ComponentSpec("MOUNT1",
														  ComponentSpec.COMPSPEC_ANY,
										 				  "java.lang.Object",
														  ComponentSpec.COMPSPEC_ANY), true);
			fail();
		}
		catch (ComponentSpecIncompatibleWithActiveComponentException ciwace)
		{
			new ExceptionIgnorer(ciwace);
			System.out.println("This is OK: "+ciwace.getMessage());
		}

		// * name generation test w/o CDB lookup
		try
		{
			ComponentInfo componentInfo = manager.getDynamicComponent(info.getHandle(),
												new ComponentSpec(ComponentSpec.COMPSPEC_ANY,
																  "IDL:alma/PS/PowerSupply:1.0",
																  "java.lang.Object",
																  "DynContainer"), false);
			assertTrue(componentInfo != null);
			//assertTrue(componentInfo.getName().startsWith("IDL:alma/PS/PowerSupply:1.0"));
			assertTrue(componentInfo.getName().startsWith("IDL:alma_PS_PowerSupply:1.0"));
			assertEquals(dynContainerInfo.getHandle(), componentInfo.getContainer());

			manager.releaseComponent(info.getHandle(), CURLHelper.createURI(componentInfo.getName()));
		}
		catch (Exception ex)
		{
			fail();
		}

		// prefix* name generation test w/o CDB lookup
		try
		{
			ComponentInfo componentInfo = manager.getDynamicComponent(info.getHandle(),
												new ComponentSpec("PREFIX"+ComponentSpec.COMPSPEC_ANY,
																  "IDL:alma/PS/PowerSupply:1.0",
																  "java.lang.Object",
																  "DynContainer"), false);
			assertTrue(componentInfo != null);
			assertTrue(componentInfo.getName().startsWith("PREFIX"));
			assertEquals(dynContainerInfo.getHandle(), componentInfo.getContainer());

			manager.releaseComponent(info.getHandle(), CURLHelper.createURI(componentInfo.getName()));
		}
		catch (Exception ex)
		{
			fail();
		}

		// * name generation test w/o CDB lookup, * container -> should fail since there is no load balancing
		try
		{
			manager.getDynamicComponent(info.getHandle(),
										new ComponentSpec(ComponentSpec.COMPSPEC_ANY,
														  "IDL:alma/newDevice/newPowerSupply:1.0",
														  "java.lang.Object",
														  ComponentSpec.COMPSPEC_ANY), false);
			fail();
		}
		catch (InvalidComponentSpecException icsex)
		{
			new ExceptionIgnorer(icsex);
			System.out.println("This is OK: "+icsex.getMessage());
		}
		catch (Exception ex)
		{
			fail();
		}

		// (*, type) and name generation test w/ container override
		try
		{
			ComponentInfo componentInfo = manager.getDynamicComponent(info.getHandle(),
												new ComponentSpec(ComponentSpec.COMPSPEC_ANY,
																  "IDL:alma/PS/PowerSupply:1.0",
																  ComponentSpec.COMPSPEC_ANY,
														  		  "DynContainer"), true);
			assertTrue(componentInfo != null);
			//assertTrue(componentInfo.getName().startsWith("IDL:alma/PS/PowerSupply:1.0"));
			assertTrue(componentInfo.getName().startsWith("IDL:alma_PS_PowerSupply:1.0"));
			assertEquals(dynContainerInfo.getHandle(), componentInfo.getContainer());

			manager.releaseComponent(info.getHandle(), CURLHelper.createURI(componentInfo.getName()));
		}
		catch (Exception ex)
		{
			fail();
		}
		

		// (name, type) - component with given name, name is exist in CDB; w/ container override
		try
		{
			ComponentInfo componentInfo = manager.getDynamicComponent(info.getHandle(),
												new ComponentSpec("PBEND_B_02",
																  "IDL:alma/PS/PowerSupply:1.0",
																  ComponentSpec.COMPSPEC_ANY,
																  "DynContainer"), true);
			assertTrue(componentInfo != null);
			assertTrue(componentInfo.getName().equals("PBEND_B_02"));
			assertEquals(dynContainerInfo.getHandle(), componentInfo.getContainer());

			manager.releaseComponent(info.getHandle(), CURLHelper.createURI(componentInfo.getName()));
		}
		catch (Exception ex)
		{
			fail();
		}

		// (name, type) - component with given name, name does not exist in CDB; w/ container override
		try
		{
			ComponentInfo componentInfo = manager.getDynamicComponent(info.getHandle(),
												new ComponentSpec("NAME_OVERRIDE",
																  "IDL:alma/PS/PowerSupply:1.0",
																  ComponentSpec.COMPSPEC_ANY,
																  "DynContainer"), true);

			assertTrue(componentInfo != null);
			assertTrue(componentInfo.getName().equals("NAME_OVERRIDE"));
			assertEquals(dynContainerInfo.getHandle(), componentInfo.getContainer());

			manager.releaseComponent(info.getHandle(), CURLHelper.createURI(componentInfo.getName()));
		}
		catch (Exception ex)
		{
			fail();
		}

		// (name, type) - but type does not exist in CDB (there is not type override)
		try
		{
			manager.getDynamicComponent(info.getHandle(),
												new ComponentSpec("NAME_OVERRIDE",
																  "IDL:alma/PS/RampedPowerSupply:1.0",
																  ComponentSpec.COMPSPEC_ANY,
																  ComponentSpec.COMPSPEC_ANY), true);
			fail();
		}
		catch (InvalidComponentSpecException icse)
		{
			new ExceptionIgnorer(icse);
			System.out.println("This is OK: "+icse.getMessage());
		}

		/*
		// (name, type) - component with given name, name does not exist in CDB; any container
		// other than "Container" container should be in the CDB
		try
		{
			ComponentInfo componentInfo = manager.getDynamicComponent(info.getHandle(),
												new ComponentSpec("NAME_OVERRIDE",
																  "IDL:alma/PS/PowerSupply:1.0",
																  ComponentSpec.COMPSPEC_ANY,
																  ComponentSpec.COMPSPEC_ANY), true);

			assertTrue(componentInfo != null);
			assertTrue(componentInfo.getName().equals("NAME_OVERRIDE"));
			//assertEquals(othercontainer.getHandle(), componentInfo.getContainer());

			manager.releaseComponent(info.getHandle(), CURLHelper.createURI(componentInfo.getName()));
		}
		catch (Exception ex)
		{
			fail();
		}
		*/
		
		// (*, type) - but type does not exist in CDB (there is not type override)
		try
		{
			manager.getDynamicComponent(info.getHandle(),
												new ComponentSpec(ComponentSpec.COMPSPEC_ANY,
																  "IDL:alma/PS/RampedPowerSupply:1.0",
																  ComponentSpec.COMPSPEC_ANY,
																  ComponentSpec.COMPSPEC_ANY), true);
			fail();
		}
		catch (InvalidComponentSpecException icse)
		{
			new ExceptionIgnorer(icse);
			System.out.println("This is OK: "+icse.getMessage());
		}

	}

	/**
	 * Test getCollocatedComponent.
	 */
	public void testGetCollocatedComponent()
	{
		URI mountURI = null;
		try {
			mountURI = new URI("MOUNT1");
		} catch (URISyntaxException e) {
			fail();
		}
		
		try
		{
			manager.getCollocatedComponent(0, null, false, null);
			fail();
		}
		catch (BadParametersException bpe)
		{
			new ExceptionIgnorer(bpe);
			System.out.println("This is OK: "+bpe.getMessage());
		}
	
		final ComponentSpec allAsterixCompSpec = new ComponentSpec(ComponentSpec.COMPSPEC_ANY,
																   ComponentSpec.COMPSPEC_ANY,
																   ComponentSpec.COMPSPEC_ANY, 
																   ComponentSpec.COMPSPEC_ANY);
	
		try
		{
			manager.getCollocatedComponent(Integer.MAX_VALUE, allAsterixCompSpec, true, dummyURI);
			fail();
		}
		catch (NoPermissionException npe)
		{
			new ExceptionIgnorer(npe);
			System.out.println("This is OK: "+npe.getMessage());
		}
	
		try
		{
			manager.getCollocatedComponent(dummyHandle, allAsterixCompSpec, false, dummyURI);
			fail();
		}
		catch (NoPermissionException npe)
		{
			new ExceptionIgnorer(npe);
			System.out.println("This is OK: "+npe.getMessage());
		}
	
	
		TestClient client = new TestClient(clientName);
		ClientInfo info = manager.login(client);
	
		assertTrue(info.getHandle() != 0);
	
		try
		{
			manager.getCollocatedComponent(info.getHandle(), null, true, dummyURI);
			fail();
		}
		catch (BadParametersException bpe)
		{
			new ExceptionIgnorer(bpe);
			System.out.println("This is OK: "+bpe.getMessage());
		}
	
		try
		{
			manager.getCollocatedComponent(info.getHandle(), allAsterixCompSpec, true, null);
			fail();
		}
		catch (BadParametersException bpe)
		{
			new ExceptionIgnorer(bpe);
			System.out.println("This is OK: "+bpe.getMessage());
		}

		try
		{
			manager.getCollocatedComponent(info.getHandle(), new ComponentSpec(null, null, null, null), false, mountURI);
			fail();
		}
		catch (BadParametersException ndce)
		{
			new ExceptionIgnorer(ndce);
			System.out.println("This is OK: "+ndce.getMessage());
		}

		
		final ComponentSpec specifiedContainerCompSpec = new ComponentSpec(ComponentSpec.COMPSPEC_ANY,
				   ComponentSpec.COMPSPEC_ANY,
				   ComponentSpec.COMPSPEC_ANY, 
				   "someContainer");

		try
		{
			manager.getCollocatedComponent(info.getHandle(), specifiedContainerCompSpec, false, mountURI);
			fail();
		}
		catch (BadParametersException ndce)
		{
			new ExceptionIgnorer(ndce);
			System.out.println("This is OK: "+ndce.getMessage());
		}

		
		// containers
		TestContainer container = new TestContainer("Container");
		Map supportedComponents = new HashMap();
		TestComponent mount1COB = new TestComponent("MOUNT1");
		supportedComponents.put("MOUNT1", mount1COB);
		TestComponent mountCollCOB = new TestComponent("MOUNT_COLLOCATED");
		supportedComponents.put("MOUNT_COLLOCATED", mountCollCOB);
		TestComponent mountColl2COB = new TestComponent("MOUNT_COLLOCATED2");
		supportedComponents.put("MOUNT_COLLOCATED2", mountCollCOB);
		container.setSupportedComponents(supportedComponents);
	
		ClientInfo containerInfo = manager.login(container);
	
		
		TestContainer dynContainer = new TestDynamicContainer("DynContainer");
	
		/*ClientInfo dynContainerInfo =*/ manager.login(dynContainer);
	
		// wait containers to startup
		try { Thread.sleep(STARTUP_COBS_SLEEP_TIME_MS); } catch (InterruptedException ie) {}

		// standard case
		try
		{
			ComponentInfo componentInfo = manager.getCollocatedComponent(info.getHandle(),
												new ComponentSpec("MOUNT_COLLOCATED", "java.lang.Object",
																  "java.lang.Object", ComponentSpec.COMPSPEC_ANY), true, mountURI);
			assertTrue(componentInfo != null);
			assertTrue(componentInfo.getName().equals("MOUNT_COLLOCATED"));
			assertEquals(containerInfo.getHandle(), componentInfo.getContainer());
		}
		catch (Exception ex)
		{
			fail();
		}
	
		// from CDB
		try
		{
			URI mount2URI = new URI("MOUNT2");
			
			ComponentInfo componentInfo = manager.getCollocatedComponent(info.getHandle(),
												new ComponentSpec("MOUNT_COLLOCATED2", "java.lang.Object",
																  "java.lang.Object", ComponentSpec.COMPSPEC_ANY), true, mount2URI);
			assertTrue(componentInfo != null);
			assertTrue(componentInfo.getName().equals("MOUNT_COLLOCATED2"));
			assertEquals(containerInfo.getHandle(), componentInfo.getContainer());
		}
		catch (Exception ex)
		{
			fail();
		}

		// from CDB, but there is not entry...
		try
		{
			URI noEntryURI = new URI("noEntry");
			
			ComponentInfo componentInfo = manager.getCollocatedComponent(info.getHandle(),
												new ComponentSpec("MOUNT_COLLOCATED3", "java.lang.Object",
																  "java.lang.Object", ComponentSpec.COMPSPEC_ANY), true, noEntryURI);
			fail();
		}
		catch (IncompleteComponentSpecException icse)
		{
			new ExceptionIgnorer(icse);
			System.out.println("This is OK: "+icse.getMessage());
		}
		catch (Exception ex)
		{
			ex.printStackTrace();
			fail();
		}
		
	}

	public void testReleaseComponent()
	{

		try
		{
			manager.releaseComponent(0, null);
			fail();
		}
		catch (BadParametersException bpe)
		{
			new ExceptionIgnorer(bpe);
			System.out.println("This is OK: "+bpe.getMessage());
		}

		try
		{
			manager.releaseComponent(Integer.MAX_VALUE, null);
			fail();
		}
		catch (BadParametersException bpe)
		{
			new ExceptionIgnorer(bpe);
			System.out.println("This is OK: "+bpe.getMessage());
		}

		try
		{
			manager.releaseComponent(dummyHandle, dummyURI);
			fail();
		}
		catch (NoPermissionException npe)
		{
			new ExceptionIgnorer(npe);
			System.out.println("This is OK: "+npe.getMessage());
		}

	}
	
	public void testMakeComponentMortal()
	{

		try
		{
			manager.makeComponentImmortal(0, null, false);
			fail();
		}
		catch (BadParametersException bpe)
		{
			new ExceptionIgnorer(bpe);
			System.out.println("This is OK: "+bpe.getMessage());
		}

		try
		{
			manager.makeComponentImmortal(Integer.MAX_VALUE, null, false);
			fail();
		}
		catch (BadParametersException bpe)
		{
			new ExceptionIgnorer(bpe);
			System.out.println("This is OK: "+bpe.getMessage());
		}

		try
		{
			manager.makeComponentImmortal(dummyHandle, dummyURI, false);
			fail();
		}
		catch (NoPermissionException npe)
		{
			new ExceptionIgnorer(npe);
			System.out.println("This is OK: "+npe.getMessage());
		}

		TestAdministrator adminClient = new TestAdministrator(administratorName);
		ClientInfo adminInfo = manager.login(adminClient);
		
		TestClient client = new TestClient(clientName);
		ClientInfo info = manager.login(client);

		assertTrue(info.getHandle() != 0);
		TestContainer container = new TestContainer("Container");
		Map supportedComponents = new HashMap();
		Component mount1 = new TestComponent("MOUNT1");
		supportedComponents.put("MOUNT1", mount1);
		Component mount2 = new TestComponent("MOUNT2");
		supportedComponents.put("MOUNT2", mount2);
		Component mount3 = new TestComponent("MOUNT3");
		supportedComponents.put("MOUNT3", mount3);
		container.setSupportedComponents(supportedComponents);

		ClientInfo containerInfo = manager.login(container);

		URI mount2URL = null;
		try
		{
			mount2URL = new URI("MOUNT2");
			StatusHolder status = new StatusHolder();
			Component ref = manager.getComponent(info.getHandle(), mount2URL, true, status);
			
			assertEquals(mount2, ref);
		}
		catch (Exception ex)
		{
			fail();
		}

		// admin will activate it
		URI mount3URL = null;
		try
		{
			mount3URL = new URI("MOUNT3");
			StatusHolder status = new StatusHolder();
			Component ref = manager.getComponent(adminInfo.getHandle(), mount3URL, true, status);
			
			assertEquals(mount3, ref);
		}
		catch (Exception ex)
		{
			fail();
		}

		try { Thread.sleep(STARTUP_COBS_SLEEP_TIME_MS); } catch (InterruptedException ie) {}

		// test activated Components
		ComponentInfo[] infos = manager.getComponentInfo(info.getHandle(), new int[0], "*", "*", true);
		assertEquals(3, infos.length);


		// make mount2 immortal (as admin which has all the rights)
		manager.makeComponentImmortal(adminInfo.getHandle(), mount2URL, true);
		infos = manager.getComponentInfo(info.getHandle(), new int[0], "MOUNT2", "*", true);
		assertEquals(1, infos.length);
		assertTrue(infos[0].getClients().contains(manager.getHandle()));
		
		manager.makeComponentImmortal(adminInfo.getHandle(), mount2URL, false);
		infos = manager.getComponentInfo(info.getHandle(), new int[0], "MOUNT2", "*", true);
		assertEquals(1, infos.length);
		assertTrue(!infos[0].getClients().contains(manager.getHandle()));
		
		// client does not own it, no permission exception expected
		try
		{
			manager.makeComponentImmortal(info.getHandle(), mount3URL, true);
			fail();
		}
		catch (NoPermissionException npe)
		{
			new ExceptionIgnorer(npe);
			System.out.println("This is OK: "+npe.getMessage());
		}

		// normal op.
		manager.makeComponentImmortal(info.getHandle(), mount2URL, true);

		manager.releaseComponent(info.getHandle(), mount2URL);
		

		// mount2 is immortal and stays active, has managers handle as an owner
		infos = manager.getComponentInfo(adminInfo.getHandle(), new int[0], "MOUNT2", "*", true);
		assertEquals(1, infos.length);
		assertTrue(infos[0].getClients().contains(manager.getHandle()));

		// mount2 should be released now
		manager.makeComponentImmortal(adminInfo.getHandle(), mount2URL, false);
		infos = manager.getComponentInfo(adminInfo.getHandle(), new int[0], "MOUNT2", "*", true);
		assertEquals(0, infos.length);
	}

	public void testComponentKeepAliveTime()
	{
		TestClient client = new TestClient(clientName);
		ClientInfo info = manager.login(client);

		assertTrue(info.getHandle() != 0);
		TestContainer container = new TestContainer("Container");
		Map supportedComponents = new HashMap();
		Component immortal = new TestComponent("IMMORTAL");
		supportedComponents.put("IMMORTAL", immortal);
		Component persistent = new TestComponent("PERSISTENT");
		supportedComponents.put("PERSISTENT", persistent);
		container.setSupportedComponents(supportedComponents);

		ClientInfo containerInfo = manager.login(container);

		URI immortalURL = null;
		try
		{
			immortalURL = new URI("IMMORTAL");
			StatusHolder status = new StatusHolder();
			Component ref = manager.getComponent(info.getHandle(), immortalURL, true, status);
			
			assertEquals(immortal, ref);
		}
		catch (Exception ex)
		{
			fail();
		}

		URI persistentURL = null;
		try
		{
			persistentURL = new URI("PERSISTENT");
			StatusHolder status = new StatusHolder();
			Component ref = manager.getComponent(info.getHandle(), persistentURL, true, status);
			
			assertEquals(persistent, ref);
		}
		catch (Exception ex)
		{
			fail();
		}

		// test activated Components
		ComponentInfo[] infos = manager.getComponentInfo(info.getHandle(), new int[0], "*", "*", true);
		assertEquals(2, infos.length);

		// IMMORTAL has to have manager as a client
		assertTrue(infos[0].getClients().contains(manager.getHandle()));
		assertTrue(!infos[1].getClients().contains(manager.getHandle()));

		// check immortality
		manager.releaseComponent(info.getHandle(), immortalURL);
		infos = manager.getComponentInfo(info.getHandle(), new int[0], "*", "*", true);
		assertEquals(2, infos.length);
		assertTrue(infos[0].getClients().contains(manager.getHandle()));

		final int KEEP_ALIVE_TIME = 5000 + 2000;

		// check keepAliveTime
		manager.releaseComponent(info.getHandle(), persistentURL);
		// both alive
		infos = manager.getComponentInfo(info.getHandle(), new int[0], "*", "*", true);
		assertEquals(2, infos.length);

		// another request for component
		try
		{
			persistentURL = new URI("PERSISTENT");
			StatusHolder status = new StatusHolder();
			Component ref = manager.getComponent(info.getHandle(), persistentURL, true, status);
			
			assertEquals(persistent, ref);
		}
		catch (Exception ex)
		{
			fail();
		}
		
		// sleep
		try { Thread.sleep(KEEP_ALIVE_TIME); } catch (InterruptedException ie) {}
		
		// still both should be activated
		infos = manager.getComponentInfo(info.getHandle(), new int[0], "*", "*", true);
		assertEquals(2, infos.length);


		
		
		manager.releaseComponent(info.getHandle(), persistentURL);
		// both alive
		infos = manager.getComponentInfo(info.getHandle(), new int[0], "*", "*", true);
		assertEquals(2, infos.length);
		
		// sleep
		try { Thread.sleep(KEEP_ALIVE_TIME); } catch (InterruptedException ie) {}

		// only IMMORTAL should be alive
		infos = manager.getComponentInfo(info.getHandle(), new int[0], "*", "*", true);
		assertEquals(1, infos.length);
		assertEquals(immortal, infos[0].getComponent());
	}

	public void testForceReleaseComponent()
	{

		try
		{
			manager.forceReleaseComponent(0, null);
			fail();
		}
		catch (BadParametersException bpe)
		{
			new ExceptionIgnorer(bpe);
			System.out.println("This is OK: "+bpe.getMessage());
		}

		try
		{
			manager.forceReleaseComponent(Integer.MAX_VALUE, null);
			fail();
		}
		catch (BadParametersException bpe)
		{
			new ExceptionIgnorer(bpe);
			System.out.println("This is OK: "+bpe.getMessage());
		}

		try
		{
			manager.forceReleaseComponent(dummyHandle, dummyURI);
			fail();
		}
		catch (NoPermissionException npe)
		{
			new ExceptionIgnorer(npe);
			System.out.println("This is OK: "+npe.getMessage());
		}


		TestAdministrator admin = new TestAdministrator(administratorName);
		ClientInfo adminInfo = manager.login(admin);

		assertTrue(adminInfo.getHandle() != 0);

		TestClient client = new TestClient(clientName);
		ClientInfo info = manager.login(client);
		
		assertTrue(info.getHandle() != 0);

		TestClient client2 = new TestClient(clientName+"2");
		ClientInfo info2 = manager.login(client2);
		
		assertTrue(info2.getHandle() != 0);

		TestContainer container = new TestContainer("Container");
		Map supportedComponents = new HashMap();
		Component mount1COB = new TestComponent("MOUNT1");
		Component mount4COB = new TestComponent("MOUNT4");
		supportedComponents.put("MOUNT1", mount1COB);
		supportedComponents.put("MOUNT4", mount4COB);
		container.setSupportedComponents(supportedComponents);

		ClientInfo containerInfo = manager.login(container);

		// client activate 
		URI mount4 = null;
		try
		{
			mount4 = new URI("MOUNT4");
			StatusHolder status = new StatusHolder();
			Component ref = manager.getComponent(info.getHandle(), mount4, true, status);
			
			assertEquals(mount4COB, ref);
			assertEquals(ComponentStatus.COMPONENT_ACTIVATED, status.getStatus());
		}
		catch (Exception ex)
		{
			fail();
		}

		// client2 activate 
		try
		{
			StatusHolder status = new StatusHolder();
			Component ref = manager.getComponent(info2.getHandle(), mount4, true, status);
			
			assertEquals(mount4COB, ref);
			assertEquals(ComponentStatus.COMPONENT_ACTIVATED, status.getStatus());
		}
		catch (Exception ex)
		{
			fail();
		}

		try { Thread.sleep(STARTUP_COBS_SLEEP_TIME_MS); } catch (InterruptedException ie) {}

		// test activated Components
		// there should be only two Components activated (MOUNT1 and MOUNT4)
		ComponentInfo[] infos = manager.getComponentInfo(info.getHandle(), new int[0], "*", "*", true);
		assertEquals(2, infos.length);
	
		// test forceful release (no permission - no admin)
		try
		{
			manager.forceReleaseComponent(info.getHandle(), mount4);
			fail();
		}
		catch (NoPermissionException npe)
		{
			new ExceptionIgnorer(npe);
			System.out.println("This is OK: "+npe.getMessage());
		}
	
		// test forceful release
		int clients = manager.forceReleaseComponent(adminInfo.getHandle(), mount4);
		assertEquals(2, clients);

		// there should be only one component activated (MOUNT1)
		infos = manager.getComponentInfo(info.getHandle(), new int[0], "*", "*", true);
		assertEquals(1, infos.length);
		
		// activate back
		// admin activate 
		try
		{
			StatusHolder status = new StatusHolder();
			Component ref = manager.getComponent(adminInfo.getHandle(), mount4, true, status);
			
			assertEquals(mount4COB, ref);
			assertEquals(ComponentStatus.COMPONENT_ACTIVATED, status.getStatus());
		}
		catch (Exception ex)
		{
			fail();
		}
		
		// there should be two components activated (MOUNT1 and MOUNT4)
		infos = manager.getComponentInfo(info.getHandle(), new int[0], "*", "*", true);
		assertEquals(2, infos.length);

		clients = manager.releaseComponent(adminInfo.getHandle(), mount4);
		assertEquals(2, clients);
		
		// there should be two components activated (MOUNT1 and MOUNT4)
		infos = manager.getComponentInfo(info.getHandle(), new int[0], "*", "*", true);
		assertEquals(2, infos.length);

		// there should be two components activated (MOUNT1 and MOUNT4)
		infos = manager.getComponentInfo(info.getHandle(), new int[0], "MOUNT4", "*", true);
		assertEquals(1, infos.length);

		IntArray compClients = infos[0].getClients(); 
		assertEquals(2, compClients.size());
		assertTrue(compClients.contains(info.getHandle()));
		assertTrue(compClients.contains(info2.getHandle()));
	}

	public void testRestartComponent()
	{

		try
		{
			manager.restartComponent(0, null);
			fail();
		}
		catch (BadParametersException bpe)
		{
			new ExceptionIgnorer(bpe);
			System.out.println("This is OK: "+bpe.getMessage());
		}

		try
		{
			manager.restartComponent(Integer.MAX_VALUE, null);
			fail();
		}
		catch (BadParametersException bpe)
		{
			new ExceptionIgnorer(bpe);
			System.out.println("This is OK: "+bpe.getMessage());
		}

		try
		{
			manager.restartComponent(dummyHandle, dummyURI);
			fail();
		}
		catch (NoPermissionException npe)
		{
			new ExceptionIgnorer(npe);
			System.out.println("This is OK: "+npe.getMessage());
		}


		TestClient client = new TestClient(clientName);
		ClientInfo info = manager.login(client);
		
		assertTrue(info.getHandle() != 0);
		
		try
		{
			manager.restartComponent(info.getHandle(), null);
			fail();
		}
		catch (BadParametersException bpe)
		{
			new ExceptionIgnorer(bpe);
			System.out.println("This is OK: "+bpe.getMessage());
		}


		URI mount = null;
		try
		{
			mount = new URI("MOUNT3");
			Component component = manager.restartComponent(info.getHandle(), mount);
			assertEquals(null, component);
		}
		catch (URISyntaxException usi)
		{
			fail();
		}

		TestContainer container = new TestContainer("Container");
		Map supportedComponents = new HashMap();
		Component mount3COB = new TestComponent("MOUNT3");
		supportedComponents.put("MOUNT3", mount3COB);
		container.setSupportedComponents(supportedComponents);

		/*ClientInfo containerInfo = */manager.login(container);

		// activate
		try
		{
			StatusHolder status = new StatusHolder();
			Component ref = manager.getComponent(info.getHandle(), mount, true, status);
			
			assertEquals(mount3COB, ref);
			assertEquals(ComponentStatus.COMPONENT_ACTIVATED, status.getStatus());
		}
		catch (Exception ex)
		{
			fail();
		}

		// restart 
		try
		{
			Component returnedComponent = manager.restartComponent(info.getHandle(), mount);
			assertEquals(mount3COB, returnedComponent);
		}
		catch (Exception ex)
		{
			fail();
		}

		// no owner client test
		TestClient client2 = new TestClient("thief");
		ClientInfo info2 = manager.login(client2);
		
		assertTrue(info2.getHandle() != 0);

		try
		{
			manager.restartComponent(info2.getHandle(), mount);
			fail();
		}
		catch (NoPermissionException npe)
		{
			new ExceptionIgnorer(npe);
			System.out.println("This is OK: "+npe.getMessage());
		}


	}

	public void testReleaseComponents()
	{
		/// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		if (false)
		{
	
			//TODO release Components
			manager.releaseComponents(0, null);
			manager.releaseComponents(Integer.MAX_VALUE, null);
	
			manager.releaseComponents(dummyHandle, new URI[] { null });
			manager.releaseComponents(dummyHandle, new URI[] { dummyURI, null });
			manager.releaseComponents(dummyHandle, new URI[] { dummyURI, null, dummyURI });
			URI[] seqURIs = new URI[] { dummyURI, dummyURI};
			manager.releaseComponents(dummyHandle, seqURIs);	

		}

	}
	
	public void testComponentInfo()
	{

		/// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		if (false)
		{
	
			//TODO get ComponentInfo
			manager.getComponentInfo(0, null, null, null, false);
			manager.getComponentInfo(Integer.MAX_VALUE, null, null, null, false);
			manager.getComponentInfo(dummyHandle, null, null, null, false);
			manager.getComponentInfo(dummyHandle, null, "non-null", null, true);
			manager.getComponentInfo(dummyHandle, null, null, "non-null", true);
			manager.getComponentInfo(dummyHandle, new int[0], null, null, false);
			manager.getComponentInfo(dummyHandle, new int[0], "non-null", null, true);
			manager.getComponentInfo(dummyHandle, new int[0], null, "non-null", false);		

		}
		
			
		try
		{
			Administrator client = new TestAdministrator(clientName);		
			ClientInfo info = manager.login(client);
			manager.getComponentInfo(info.getHandle(), new int[0], "*MOUNT*", "*", false);
			manager.logout(info.getHandle());
		}
		catch (Throwable e)
		{
			e.printStackTrace();
			fail(e.getMessage());
		}



		TestContainer container = new TestContainer("Container");
		Map supportedComponents = new HashMap();
		Component mount1COB = new TestComponent("MOUNT1");
		supportedComponents.put("MOUNT1", mount1COB);
		Component mount4COB = new TestComponent("MOUNT4");
		supportedComponents.put("MOUNT4", mount4COB);
		container.setSupportedComponents(supportedComponents);

		ClientInfo containerInfo = manager.login(container);

		try
		{
			Thread.sleep(STARTUP_COBS_SLEEP_TIME_MS);
		} catch (InterruptedException ie)
		{
		}

		try
		{
			Administrator client = new TestAdministrator(clientName);		
			ClientInfo info = manager.login(client);
			ComponentInfo[] infos = manager.getComponentInfo(info.getHandle(), new int[0], "MOUNT1", "*", false);
			assertEquals(1, infos.length);
		}
		catch (Throwable e)
		{
			e.printStackTrace();
			fail(e.getMessage());
		}

		manager.logout(containerInfo.getHandle());

	}

	public void testPing()
	{		
		/// !!! this takes a lot of time (and not fully implemtented)
		if (true) return;

		ClientInfo info = manager.login(new TestClient(clientName));

		try
		{
			Thread.sleep(12000);
		}
		catch (InterruptedException ie) {}
		
		manager.logout(info.getHandle());
		System.out.println("logged out.");
		
		try
		{
			Thread.sleep(SLEEP_TIME_MS);
		}
		catch (InterruptedException ie) {}

		// no pings here
	}

	private void checkForNotification(ArrayList queue, Object event)
	{
		synchronized (queue) {
			if (queue.size() == 0)
			{
				try {
					queue.wait(1000);
				} catch (InterruptedException e) { /* noop */ }
			}
			
			assertEquals(1, queue.size());
			assertEquals(event, queue.get(0));
			queue.clear();
		}
	}
	
	public void testAdministratorNotifications()
	{
		TestAdministrator admin = new TestAdministrator("admin", true);
		ClientInfo adminInfo = manager.login(admin);
		assertNotNull(adminInfo);

		TestAdministrator admin2 = new TestAdministrator("admin2", true);
		ClientInfo adminInfo2 = manager.login(admin2);
		assertNotNull(adminInfo2);
		checkForNotification(admin.getClientLoggedInNotifications(), adminInfo2);
		
		TestAdministrator admin3 = new TestAdministrator("admin3", true);
		ClientInfo adminInfo3 = manager.login(admin3);
		assertNotNull(adminInfo3);
		checkForNotification(admin.getClientLoggedInNotifications(), adminInfo3);
		checkForNotification(admin2.getClientLoggedInNotifications(), adminInfo3);

		
		// test client login notification
		Client client = new TestClient("client");
		ClientInfo clientInfo = manager.login(client);
		assertNotNull(clientInfo);
		checkForNotification(admin.getClientLoggedInNotifications(), clientInfo);
		checkForNotification(admin2.getClientLoggedInNotifications(), clientInfo);
		checkForNotification(admin3.getClientLoggedInNotifications(), clientInfo);
		
		// test container login notification
		Container container = new TestContainer("Container");
		ClientInfo containerInfo = manager.login(container);
		assertNotNull(containerInfo);
		Integer h = new Integer(containerInfo.getHandle());
		checkForNotification(admin.getContainerLoggedInNotifications(), h);
		checkForNotification(admin2.getContainerLoggedInNotifications(), h);
		checkForNotification(admin3.getContainerLoggedInNotifications(), h);

		manager.logout(containerInfo.getHandle());
		checkForNotification(admin.getContainerLoggedOutNotifications(), h);
		checkForNotification(admin2.getContainerLoggedOutNotifications(), h);
		checkForNotification(admin3.getContainerLoggedOutNotifications(), h);

		manager.logout(clientInfo.getHandle());
		h = new Integer(clientInfo.getHandle());
		checkForNotification(admin.getClientLoggedOutNotifications(), h);
		checkForNotification(admin2.getClientLoggedOutNotifications(), h);
		checkForNotification(admin3.getClientLoggedOutNotifications(), h);
		
		manager.logout(adminInfo3.getHandle());
		h = new Integer(adminInfo3.getHandle());
		checkForNotification(admin.getClientLoggedOutNotifications(), h);
		checkForNotification(admin2.getClientLoggedOutNotifications(), h);

		manager.logout(adminInfo2.getHandle());
		h = new Integer(adminInfo2.getHandle());
		checkForNotification(admin.getClientLoggedOutNotifications(), h);

		manager.logout(adminInfo.getHandle());
		
		// test
		assertEquals(0, admin.getClientLoggedInNotifications().size());
		assertEquals(0, admin.getClientLoggedOutNotifications().size());
		assertEquals(0, admin.getContainerLoggedInNotifications().size());
		assertEquals(0, admin.getContainerLoggedOutNotifications().size());

		assertEquals(0, admin2.getClientLoggedInNotifications().size());
		assertEquals(0, admin2.getClientLoggedOutNotifications().size());
		assertEquals(0, admin2.getContainerLoggedInNotifications().size());
		assertEquals(0, admin2.getContainerLoggedOutNotifications().size());

		assertEquals(0, admin3.getClientLoggedInNotifications().size());
		assertEquals(0, admin3.getClientLoggedOutNotifications().size());
		assertEquals(0, admin3.getContainerLoggedInNotifications().size());
		assertEquals(0, admin3.getContainerLoggedOutNotifications().size());
	}

	public void testManagerIsServiceComponent()
	{
		assertTrue(manager.isServiceComponent("Log"));
		assertTrue(manager.isServiceComponent("NotifyEventChannelFactory"));
		assertTrue(manager.isServiceComponent("LoggingChannel"));
		assertTrue(manager.isServiceComponent("PDB"));
		assertTrue(!manager.isServiceComponent("invalid"));
	}
	
	public void testManagerToContainerStateTransferComponents()
	{

		TestComponent mount1COB = new TestComponent("MOUNT1");
		TestComponent mount2COB = new TestComponent("MOUNT2");
		
		Map supportedComponents = new HashMap();
		supportedComponents.put("MOUNT1", mount1COB);
		supportedComponents.put("MOUNT2", mount2COB);


		TestContainer container  = new TestContainer("Container");
		container.setSupportedComponents(supportedComponents);
		
		// recovery mode
		TestContainer container2 = new TestContainer("Container", "AR");
		container2.setSupportedComponents(supportedComponents);

		// container login
		/*ClientInfo containerInfo =*/ manager.login(container);
		
		TestAdministrator client = new TestAdministrator(administratorName);
		ClientInfo info = manager.login(client);

		// activate MOUNT2
		//
		URI mount1URI;
		URI mount2URI;
		try
		{
			mount1URI = new URI("MOUNT1");	
			mount2URI = new URI("MOUNT2");	
			StatusSeqHolder status = new StatusSeqHolder();
			Component[] ref = manager.getComponents(info.getHandle(), new URI[] { mount1URI, mount2URI }, true, status);
			
			assertEquals(2, ref.length);
			
			assertEquals(mount1COB, ref[0]);
			assertEquals(ComponentStatus.COMPONENT_ACTIVATED, status.getStatus()[0]);

			assertEquals(mount2COB, ref[1]);
			assertEquals(ComponentStatus.COMPONENT_ACTIVATED, status.getStatus()[1]);
		}
		catch (Exception ex)
		{
			fail();
		}

		try { Thread.sleep(STARTUP_COBS_SLEEP_TIME_MS); } catch (InterruptedException ie) {}

		// now do the trick, make container2 to login
		// this will assime container is down
		ClientInfo containerInfo2 = manager.login(container2);

		try { Thread.sleep(STARTUP_COBS_SLEEP_TIME_MS); } catch (InterruptedException ie) {}

		// there should be 2 Components activated
		ComponentInfo[] infos = manager.getComponentInfo(info.getHandle(), new int[0], "*", "*", true);
		assertEquals(2, infos.length);

		assertTrue("MOUNT1".equals(infos[0].getName()));
		assertTrue("MOUNT2".equals(infos[1].getName()));
		
		// container2 took over
		assertEquals(containerInfo2.getHandle(), infos[0].getContainer());
		assertEquals(containerInfo2.getHandle(), infos[1].getContainer());

		// manager and client
		assertEquals(2, infos[0].getClients().size());
		assertTrue(infos[0].getClients().contains(info.getHandle()));
		assertTrue(infos[0].getClients().contains(HandleConstants.MANAGER_MASK));

		// client only
		assertEquals(1, infos[1].getClients().size());
		assertTrue(infos[1].getClients().contains(info.getHandle()));

	}

	public void testContainerToManagerStateTransferComponents()
	{
		TestComponent mount1COB = new TestComponent("MOUNT1");
		TestComponent mount2COB = new TestComponent("MOUNT2");
		
		Map supportedComponents = new HashMap();
		supportedComponents.put("MOUNT1", mount1COB);
		supportedComponents.put("MOUNT2", mount2COB);


		// dummy container
		TestContainer dummyContainer  = new TestContainer("Container", "AR");
		ClientInfo dummyContainerInfo = manager.login(dummyContainer);
		dummyContainer.setSupportedComponents(supportedComponents);

		try { Thread.sleep(STARTUP_COBS_SLEEP_TIME_MS); } catch (InterruptedException ie) {}

		TestAdministrator client = new TestAdministrator(administratorName);
		ClientInfo info = manager.login(client);

		// activate MOUNT2
		//
		URI mount2URI;
		try
		{
			mount2URI = new URI("MOUNT2");	
			StatusHolder status = new StatusHolder();
			Component ref = manager.getComponent(info.getHandle(), mount2URI, true, status);
			
			assertEquals(mount2COB, ref);
			assertEquals(ComponentStatus.COMPONENT_ACTIVATED, status.getStatus());
		}
		catch (Exception ex)
		{
			fail();
		}


		// try to confuse with recovery mode
		TestContainer container  = new TestContainer("Container", "AR");
		container.setSupportedComponents(supportedComponents);

		// add Components to container
		ComponentInfo mount1COBInfo = new ComponentInfo(HandleConstants.COMPONENT_MASK + 1, "MOUNT1", "IDL:alma/MOUNT_ACS/Mount:1.0", "acsexmplMount", mount1COB);
		mount1COBInfo.setInterfaces(mount1COB.implementedInterfaces());
		mount1COBInfo.setContainer(dummyContainerInfo.getHandle());
		mount1COBInfo.setContainerName(dummyContainerInfo.getName());
		container.getActivatedComponents().put(new Integer(mount1COBInfo.getHandle()), mount1COBInfo); 

		ComponentInfo mount2COBInfo = new ComponentInfo(HandleConstants.COMPONENT_MASK + 2, "MOUNT2", "IDL:alma/MOUNT_ACS/Mount:1.0", "acsexmplMount", mount2COB);
		mount2COBInfo.setInterfaces(mount2COB.implementedInterfaces());
		mount2COBInfo.setContainer(dummyContainerInfo.getHandle());
		mount2COBInfo.setContainerName(dummyContainerInfo.getName());
		container.getActivatedComponents().put(new Integer(mount2COBInfo.getHandle()), mount2COBInfo); 

		// container login
		ClientInfo containerInfo = manager.login(container);
		
		try { Thread.sleep(STARTUP_COBS_SLEEP_TIME_MS); } catch (InterruptedException ie) {}

		// there should be 2 Components activated
		ComponentInfo[] infos = manager.getComponentInfo(info.getHandle(), new int[0], "*", "*", true);
		assertEquals(2, infos.length);

		assertTrue("MOUNT1".equals(infos[0].getName()));
		assertTrue("MOUNT2".equals(infos[1].getName()));
		
		// container2 took over
		assertEquals(containerInfo.getHandle(), infos[0].getContainer());
		assertEquals(containerInfo.getHandle(), infos[1].getContainer());

		// manager
		assertEquals(1, infos[0].getClients().size());
		assertTrue(infos[0].getClients().contains(HandleConstants.MANAGER_MASK));

		// client only
		assertEquals(1, infos[1].getClients().size());
		assertTrue(infos[1].getClients().contains(info.getHandle()));

	}

	//TODO test all info after logout
	//TODO test duplicate login and used Components info 
	

	
	//TODO test all info after logout
	//TODO test duplicate login and used Components info 
	
	public static TestSuite suite() {
		return new TestSuite(ManagerImplTest.class);
	}

	public static void main(String[] args) {
		junit.textui.TestRunner.run(ManagerImplTest.class);
		System.exit(0);
	}

}
